#include <stdio.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <SDL2/SDL.h>

int main() {
    AVFormatContext* formatContext = NULL;
    AVCodecContext* codecContext = NULL;
    AVCodec* codec = NULL;
    AVFrame* frame = NULL;
    AVPacket packet;

    av_register_all();

    if (avformat_open_input(&formatContext, "path/to/video.mp4", NULL, NULL) != 0) {
        fprintf(stderr, "Failed to open video file.\n");
        return -1;
    }

    if (avformat_find_stream_info(formatContext, NULL) < 0) {
        fprintf(stderr, "Failed to retrieve stream information.\n");
        return -1;
    }

    int videoStreamIndex = -1;
    for (int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }

    if (videoStreamIndex == -1) {
        fprintf(stderr, "No video stream found.\n");
        return -1;
    }

    codecContext = avcodec_alloc_context3(NULL);
    avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar);

    codec = avcodec_find_decoder(codecContext->codec_id);
    if (codec == NULL) {
        fprintf(stderr, "Failed to find video decoder.\n");
        return -1;
    }

    if (avcodec_open2(codecContext, codec, NULL) < 0) {
        fprintf(stderr, "Failed to open video decoder.\n");
        return -1;
    }

    frame = av_frame_alloc();

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Video Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, codecContext->width, codecContext->height, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, codecContext->width, codecContext->height);

    while (av_read_frame(formatContext, &packet) >= 0) {
        if (packet.stream_index == videoStreamIndex) {
            avcodec_send_packet(codecContext, &packet);
            while (avcodec_receive_frame(codecContext, frame) == 0) {
                SDL_UpdateYUVTexture(texture, NULL, frame->data[0], frame->linesize[0], frame->data[1], frame->linesize[1], frame->data[2], frame->linesize[2]);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);
            }
        }
        av_packet_unref(&packet);
    }

    av_frame_free(&frame);
    avcodec_close(codecContext);
    avformat_close_input(&formatContext);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


/*Please note that the above code is a simplified example and may not handle all possible scenarios. It uses FFmpeg for decoding video frames and SDL (Simple DirectMedia Layer) for rendering the frames to the screen. Make sure to install the necessary libraries (libavformat, libavcodec, libswscale, and SDL2) and link them correctly during compilation.

To compile the code, you need to install the necessary development libraries and headers for FFmpeg and SDL. Assuming you have the required libraries installed, you can compile the code using the following command:*/

/*gcc video_player.c -o video_player -lavformat -lavcodec -lswscale -lSDL2*/

/*Replace video_player.c with the filename of your source code file. The resulting executable (video_player) can then be run to play a video file specified by the path in the code (path/to/video.mp4).*/

/*Please note that building a full-featured video player with advanced functionalities is a significantly more complex task. Libraries like FFmpeg provide extensive APIs for handling different formats, audio synchronization, seeking, and other advanced features. Consider exploring the official documentation and examples of the libraries to learn more and expand the functionality as needed.*/
#include <stdio.h>

#include <string.h>

#include <SDL3/SDL.h>

#define WIDTH  640
#define HEIGHT 480

static uint8_t pixels[WIDTH * HEIGHT * 4];


static void make_gradient(uint8_t *pixels)
{
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            const size_t pixel = ((size_t)y * (size_t)WIDTH + (size_t)x)
                               * (size_t)4;
            pixels[pixel + 0] = (uint8_t)((x * 255) / (WIDTH - 1));
            pixels[pixel + 1] = (uint8_t)((y * 255) / (HEIGHT - 1));
            pixels[pixel + 2] = 64;
            pixels[pixel + 3] = 255;
        }
    }
}


 void make_gradient_no_div(uint8_t *pixels)
{
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            const size_t pixel = ((size_t)y * (size_t)WIDTH + (size_t)x)
                               * (size_t)4;
            pixels[pixel + 0] = (uint8_t)((x * 255));
            pixels[pixel + 1] = (uint8_t)((y * 255));
            pixels[pixel + 2] = 64;
            pixels[pixel + 3] = 255;
        }
    }
}

void make_gradient_unique (uint8_t *pixels)
{
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            const size_t pixel = ((size_t)y * (size_t)WIDTH + (size_t)x)
                               * (size_t)4;
            *(pixels + pixel + 0 ) = (uint8_t) ( (x * 255 ) / (WIDTH -1 ) ) ;
            *(pixels + pixel + 1 ) = (uint8_t) ( (y * 255 ) / (HEIGHT -1 )) ;
            *(pixels + pixel + 2 ) = (uint8_t) ( (((WIDTH -1 ) - x) * 255 ) / (WIDTH -1 )) ;
            *(pixels + pixel + 3 ) = (uint8_t) ( 255 ) ;
            
        }
    }
}

void make_gradient_blue(uint8_t *pixels)
{
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            const size_t pixel = ((size_t)y * (size_t)WIDTH + (size_t)x)
                               * (size_t)4;
            pixels[pixel + 0] = (uint8_t)(0);
            pixels[pixel + 1] = (uint8_t)(0);
            pixels[pixel + 2] = 64;
            pixels[pixel + 3] = 255;
        }
    }
}

int main(void)
{
    memset(pixels, 255, sizeof(pixels));  // white RGBA pixels

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("pixels gradients", WIDTH, HEIGHT, 0);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }


    make_gradient(pixels) ;
    // make_gradient_unique(pixels) ;
    
    
    printf (" vales for first few pixels : \n") ;
    for (int i = 0; i < 16; i++)
    {
        printf("%x : " ,pixels[i] ) ;
    }
    printf("\n ") ;    
    
    printf("%x \n" , *(uint32_t *)pixels) ;

    // Wraps pixels without copying. pitch is bytes per row: WIDTH * 4.
    SDL_Surface *image =
        SDL_CreateSurfaceFrom(WIDTH, HEIGHT, SDL_PIXELFORMAT_RGBA32,
                              pixels, WIDTH * 4);
    if (image == NULL) {
        SDL_Log("SDL_CreateSurfaceFrom: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(window);
    if (screen == NULL ||
        !SDL_BlitSurface(image, NULL, screen, NULL) ||
        !SDL_UpdateWindowSurface(window)) {
        SDL_Log("Display: %s", SDL_GetError());
        SDL_DestroySurface(image);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT ||
            event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
            break;
        }
    }

    SDL_DestroySurface(image);  // does not free pixels
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
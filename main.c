#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{
    char buffer[100];
    fgets(buffer, 100, stdin); 
    fgets(buffer, 100, stdin); 

    int width, height, max_val;
    // get dimensions of img
    scanf("%d %d", &width, &height);
    scanf("%d", &max_val);
    fgetc(stdin); 

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    SDL_Rect pixel;
    pixel.w = 1;
    pixel.h = 1;

    // loop to print image pixel by pixel
    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            unsigned char r = getchar();
            unsigned char g = getchar();
            unsigned char b = getchar();

            pixel.x = x;
            pixel.y = y;

            Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
            SDL_FillRect(psurface, &pixel, color);
        }
    }

    SDL_UpdateWindowSurface(pwindow);

    SDL_Event event;
    int app_running = 1;

    // keep window running
    while (app_running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                app_running = 0;
            }
        }
        SDL_Delay(100); 
    }

    return 0;
}
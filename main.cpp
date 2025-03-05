#include <iostream>
#include <memory>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "SupportingResources/FileIO/FileIOSample.h"

struct myStruct {
    std::string name;

    explicit myStruct(const std::string& _name) {
        name = _name;
        printf("hiiii, I am %s\n", name.c_str());
    }

    ~myStruct() {
        printf("%s goes byeeeee\n", name.c_str());
    }
};


int main() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("ERR : %s\n", SDL_GetError());
    }

    // Set up window, renderer
    SDL_Window* window = SDL_CreateWindow("My Window!", 25,25, 500, 500, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

//    samples::readFile();
//    samples::writeFile();

    {
        myStruct obj("noPointer");
        // end of scope reached, object deconstructs itself
    }

    {
        myStruct* ptr = new myStruct("Pointer");
//        delete ptr; // very important!!!!
        // end of scope, pointer will be lost, but the object WONT be destroyed automatically
    }

    {
        // Well if we know objects automatically deconstruct, why not put the pointer into an object?
        // then when the object deconstructs, it can delete the pointer for us!
        std::unique_ptr<myStruct> ptr = std::make_unique<myStruct>("uniquePointer!");
    }


    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                running = false; // exit the running loop
            }
        }


        // Set up objects to draw

        SDL_Rect
        SDL_RenderFillRect(renderer, )



        // Draw from renderer and reset it
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

    }


    return 0;
}

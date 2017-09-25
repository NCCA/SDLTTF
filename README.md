# SDLTTF
![alt tag](http://nccastaff.bournemouth.ac.uk/jmacey/GraphicsLib/Demos/TTFText.png)

As the ngl::Text class is reliant upon QFont at present this class is a drop in replacment using  [sdl-ttf] (https://www.libsdl.org/projects/SDL_ttf/)
eventually all of this will be merged into the core ngl with compile time flags to choose the text rendering engine.

Note the following is added to the copy commands for shadow build

`copydata.commands += mkdir -p $$OUT_PWD/font ;`

`copydata.commands += $(COPY_DIR) $$PWD/font/* $$OUT_PWD/font/ ;`

as we need to copy the font to the run directory as well

The SDL2_ttf library also needs to be added to link using

`LIBS+=-lSDL2_ttf`

Make sure if you need to use the classes you add the same to your .pro file.

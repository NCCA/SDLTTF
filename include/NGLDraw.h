#ifndef NGLDRAW_H_
#define NGLDRAW_H_

#include <SDL.h>
#include <ngl/Mat4.h>
#include "Text.h"

class NGLDraw
{
  public :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor this will have a valid OpenGL context so we can create gl stuff
    //----------------------------------------------------------------------------------------------------------------------
    NGLDraw();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor used to remove any NGL stuff created
    //----------------------------------------------------------------------------------------------------------------------
    ~NGLDraw();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief resize our screen and set the camera aspect ratio
    /// @param[in] _w the new width
    /// @param[in] _h the new height
    //----------------------------------------------------------------------------------------------------------------------
    void resize(int _w, int _h);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief draw the scene
    //----------------------------------------------------------------------------------------------------------------------
    void draw();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the SDL mouse event structure containing all mouse info
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (const SDL_MouseMotionEvent &_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse button is presses
    /// @param _event the SDL mouse event structure containing all mouse info
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent (const SDL_MouseButtonEvent &_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// @param _event the SDL mouse event structure containing all mouse info
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent (const SDL_MouseButtonEvent &_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// @param _event the SDL mouse event structure containing all mouse info
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent(const SDL_MouseWheelEvent &_event);
  private :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to load transform data to the shaders
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatricesToShader();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the x rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinXFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the y rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinYFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_rotate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the Right mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_translate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origY;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origXPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origYPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the global mouse transforms
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_mouseGlobalTX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our Camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_view;
    ngl::Mat4 m_project;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the model position for mouse movement
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_modelPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief a simple light use to illuminate the screen
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<Text> m_text;
};


#endif

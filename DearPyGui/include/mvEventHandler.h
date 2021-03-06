#pragma once

//-----------------------------------------------------------------------------
// mvEventHandler
//
//     - This is a temporary class for v1.0 until a more complete event 
//       handling system is put in place. Which will be required for the
//       upcoming v2.0 custom widget API.
//     
//     - Currently this is used by mvWindowAppItem and mvApp
//-----------------------------------------------------------------------------

#include <string>
#define PY_SSIZE_T_CLEAN
#include <Python.h>

namespace Marvel {

    //-----------------------------------------------------------------------------
    // mvEventHandler
    //-----------------------------------------------------------------------------
    class mvEventHandler
    {

    public:

        mvEventHandler() = default;

        [[nodiscard]] bool isMouseHandled   () const { return m_handleMouse; }
        [[nodiscard]] bool isKeyboardHandled() const { return m_handleKeyboard; }

        //-----------------------------------------------------------------------------
        // Callbacks
        //-----------------------------------------------------------------------------
        void setRenderCallback          (PyObject* callback) { m_renderCallback = callback; }
        void setResizeCallback          (PyObject* callback) { m_resizeCallback = callback; }
        void setMouseMoveCallback       (PyObject* callback) { m_mouseMoveCallback = callback; }
        void setOnCloseCallback         (PyObject* callback) { m_onCloseCallback = callback; }
        void setOnStartCallback         (PyObject* callback) { m_onStartCallback = callback; }
        void setMouseClickCallback      (PyObject* callback) { m_handleMouse    = true; m_mouseClickCallback = callback; }
        void setMouseDownCallback       (PyObject* callback) { m_handleMouse    = true; m_mouseDownCallback = callback; }
        void setMouseDoubleClickCallback(PyObject* callback) { m_handleMouse    = true; m_mouseDoubleClickCallback = callback; }
        void setMouseReleaseCallback    (PyObject* callback) { m_handleMouse    = true; m_mouseReleaseCallback = callback; }
        void setMouseWheelCallback      (PyObject* callback) { m_handleMouse    = true; m_mouseWheelCallback = callback; }
        void setMouseDragCallback       (PyObject* callback) { m_handleMouse    = true; m_mouseDragCallback = callback; }
        void setKeyDownCallback         (PyObject* callback) { m_handleKeyboard = true; m_keyDownCallback = callback; }
        void setKeyPressCallback        (PyObject* callback) { m_handleKeyboard = true; m_keyPressCallback = callback; }
        void setKeyReleaseCallback      (PyObject* callback) { m_handleKeyboard = true; m_keyReleaseCallback = callback; }

        [[nodiscard]] PyObject* getRenderCallback          (){ return m_renderCallback; }
        [[nodiscard]] PyObject* getResizeCallback          (){ return m_resizeCallback; }
        [[nodiscard]] PyObject* getMouseReleaseCallback    (){ return m_mouseReleaseCallback; }
        [[nodiscard]] PyObject* getMouseClickCallback      (){ return m_mouseClickCallback; }
        [[nodiscard]] PyObject* getMouseDownCallback       (){ return m_mouseDownCallback; }
        [[nodiscard]] PyObject* getMouseDoubleClickCallback(){ return m_mouseDoubleClickCallback; }
        [[nodiscard]] PyObject* getMouseDragCallback       (){ return m_mouseDragCallback; }
        [[nodiscard]] PyObject* getKeyDownCallback         (){ return m_keyDownCallback; }
        [[nodiscard]] PyObject* getKeyPressCallback        (){ return m_keyPressCallback; }
        [[nodiscard]] PyObject* getKeyReleaseCallback      (){ return m_keyReleaseCallback; }
        [[nodiscard]] PyObject* getMouseWheelCallback      (){ return m_mouseWheelCallback; }
        [[nodiscard]] PyObject* getMouseMoveCallback       (){ return m_mouseMoveCallback; }
        [[nodiscard]] PyObject* getOnCloseCallback         (){ return m_onCloseCallback; }
        [[nodiscard]] PyObject* getOnStartCallback         (){ return m_onStartCallback; }

    private:

        // standard callbacks
        PyObject* m_renderCallback;
        PyObject* m_mouseDownCallback;
        PyObject* m_mouseClickCallback;
        PyObject* m_mouseReleaseCallback;
        PyObject* m_mouseDoubleClickCallback;
        PyObject* m_mouseWheelCallback;
        PyObject* m_mouseDragCallback;
        PyObject* m_keyDownCallback;
        PyObject* m_keyPressCallback;
        PyObject* m_keyReleaseCallback;
        PyObject* m_resizeCallback;
        PyObject* m_mouseMoveCallback;
        PyObject* m_onCloseCallback;
        PyObject* m_onStartCallback;

        bool   m_handleMouse    = false;
        bool   m_handleKeyboard = false;  
    };
}
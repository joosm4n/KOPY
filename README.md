# KOPY C++ Graphics & Physics Library

KOPY is a C++ library for 2D graphics, texture management, event handling, and basic physics/collision, built on SDL3. It provides a simple API for rendering, input, and game logic.

## Initialization & Window Management
- **InitKOPY()**: Initialize the KOPY library.
- **SetScriptPath(char\* path)**: Set the script directory for assets.
- **SetAssetsPath(char\* path)**: Set the assets directory (if needed).
- **OpenKOPYWindow(int width, int height)**: Create and open an SDL window and renderer.
- **CloseKOPYWindow()**: Destroy the window and renderer, clean up SDL.

## Rendering & Drawing
- **SetDrawColor(int r, int g, int b, int a)**: Set the renderer's draw color.
- **SetScreenColor(int r, int g, int b, int a)**: Set the background color for clearing.
- **StartFrame()**: Begin a new frame (clear screen, set color).
- **RenderFrame()**: Present the frame and poll events.

### Geometry Drawing
- **DrawLine(float x1, float y1, float x2, float y2)**: Draw a line.
- **DrawCircle(int x, int y, int radius)**: Draw a circle outline.
- **DrawFilledCircle(int x, int y, int radius)**: Draw a filled circle.
- **DrawRect(int x, int y, int w, int h, int rotation)**: Draw a rectangle (optionally rotated).

## Texture Management
- **LoadTexture(char\* filename)**: Load a texture from file. Returns texture index.
- **ShowTexture(unsigned int index)**: Show texture for rendering.
- **HideTexture(unsigned int index)**: Hide texture from rendering.
- **PlaceTexture(index, x, y, w, h)**: Move, resize, and show texture.
- **MoveTexture(index, x, y)**: Move texture to position.
- **PushTexture(index, dx, dy)**: Offset texture position.
- **RotateTexture(index, degrees)**: Rotate texture.
- **SetVel(index, Vec2 vel)**: Set velocity for physics.
- **SetRotVel(index, float rotVel)**: Set rotational velocity for physics.

## Event Handling
- **PollEvents()**: Poll SDL events (keyboard, quit, etc).
- **KeyPressed(unsigned int key)**: Check if a key is pressed.
- **WaitForKeypress(unsigned int key)**: Block until key is pressed.

## Physics & Collision
- **UpdatePhysics()**: Update physics and resolve collisions for all objects.

## Utility & Testing
- **ImportString(char\* buffer)**: Test string import.
- **PassingVec2(Vec2 vec)**: Test passing a vector.
- **ReturnVec2(Vec2 vecIn)**: Test returning a vector.

## Timing
- **DelayMS(int ms)**: Delay for milliseconds.
- **DelayS(int s)**: Delay for seconds.

## Game-Specific
- **CreateAsteroid(Vec2 pos, Vec2 size)**: Create an asteroid object with physics and collision.

---

### Types
- **Vec2**: 2D vector type for positions, velocities, etc.
- **Transform**: Stores position, size, rotation, velocity, and physics properties for objects.

### Notes
- All drawing and texture functions require the window to be open and initialized.
- Physics/collision is basic (circle-based, impulse resolution).
- Asset/script paths must be set before loading textures.
- Uses SDL3 for graphics and input.

---

For more details, see the header files and source code for each subsystem (texturehandler, eventhandler, collisionhandler, transform, KO_Maths).

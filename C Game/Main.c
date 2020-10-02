#include <stdio.h>;

#pragma warning(push,3)
#include <windows.h>;
#pragma warning(pop)


LRESULT CALLBACK MainWndowProc(HWND WindowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance,PSTR CommandLine, INT CmdShow)
{
    
    UNREFERENCED_PARAMETER(PreviousInstance);
    UNREFERENCED_PARAMETER(CommandLine);
    UNREFERENCED_PARAMETER(CmdShow);

    MSG Message = { 0 };

    while (GetMessageA(&Message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Message);

        DispatchMessageA(&Message);
    }

    WNDCLASSEXA WindowClass = { 0 };
    HWND WindowHandle;

    //Step 1: Registering the Window Class
    WindowClass.cbSize = sizeof(WNDCLASSEXA);
    WindowClass.style = 0;
    WindowClass.lpfnWndProc = MainWndowProc;
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = Instance;
    WindowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
    WindowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WindowClass.lpszMenuName = NULL;
    WindowClass.lpszClassName = "C_GAME_WINDOWCLASS";
    WindowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (RegisterClassExA(&WindowClass) == 0)
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    WindowHandle = CreateWindowExA(WS_EX_CLIENTEDGE,WindowClass.lpszClassName,"C Game  Title",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,NULL, NULL, Instance, NULL);

    if (WindowHandle == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(WindowHandle, CmdShow);
    UpdateWindow(WindowHandle);


    
    return 0;
}

LRESULT CALLBACK MainWndowProc(
    HWND WindowHandle,        // handle to window
    UINT uMsg,        // message identifier
    WPARAM wParam,    // first message parameter
    LPARAM lParam)    // second message parameter
{

    switch (uMsg)
    {
        case WM_CREATE:
            // Initialize the window. 
            return 0;

        case WM_PAINT:
            // Paint the window's client area. 
            return 0;

        case WM_SIZE:
            // Set the size and position of the window. 
            return 0;

        case WM_DESTROY:
            // Clean up window-specific data objects. 
            return 0;

            // 
            // Process other messages. 
            // 

        default:
            return DefWindowProc(WindowHandle, uMsg, wParam, lParam);
    }
    return 0;
}
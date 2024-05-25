
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    int num;
    string name;
    string path1;
    string path2;
    bool err;
    HANDLE cFile;
    char wFile[100];
    char yn[3];

    cout << "Please Enter a Number" << endl;
    cout << "1: Create Directory" << endl;
    cout << "2: Remove Directory" << endl;
    cout << "3: Copy File" << endl;
    cout << "4: Move File" << endl;
    cout << "5: Create File" << endl;
    cout << "6: Write File" << endl;
    cout << "7: Read File" << endl;
    cout << "Enter: ";
    cin >> num;

    switch(num)
    {
    case 1:
        cout << "Please Enter PATH For Directory: " << endl;
        cout << "Enter: ";
        cin >> path1;

        err = CreateDirectory((path1).c_str(), NULL);

        if(err == false)
        {
            if(GetLastError() == 183)
            {
                cout << "This Directory Already Exists!" << endl;
            }
            else
            {
                cout << "Opertaion Failed" << endl;
                cout << GetLastError() << endl;
            }
            break;
        }

    case 2:
        cout << "Please Enter PATH For Directory: " << endl;
        cout << "Enter: ";
        cin >> path1;

        err = RemoveDirectory((path1).c_str());

        if(err == false)
        {
            if(GetLastError() == 2)
            {
                cout << "There Is Not Such a Directory!" << endl;
            }
            else
            {
                cout << "Opertaion Failed" << endl;
                cout << GetLastError() << endl;
            }
        }
        break;

    case 3:
        cout << "Please Enter PATH Of The File You Want To Copy: " << endl;
        cout << "Enter: ";
        cin >> path1;

        cout << "Please Enter Destination path1: " << endl;
        cout << "Enter: ";
        cin >> path2;

        err = CopyFile((path1).c_str(), (path2).c_str(), true);

        if(err == false)
        {
            cout << "Opertaion Failed" << endl;
            cout << GetLastError() << endl;
        }
        break;

    case 4:
        cout << "Please Enter PATH Of The File You Want To Move: " << endl;
        cout << "Enter: ";
        cin >> path1;

        cout << "Please Enter Destination path1: " << endl;
        cout << "Enter: ";
        cin >> path2;

        err = MoveFile((path1).c_str(), (path2).c_str());

        if(err == false)
        {
            cout << "Opertaion Failed" << endl;
            cout << GetLastError() << endl;
        }
        break;

    case 5:
        cout << "Please Enter PATH of The File You Want To Create: " << endl;
        cout << "Enter: ";
        cin >> path1;

        cFile = CreateFile(
        ((path1).c_str()),
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        );


        if(cFile == INVALID_HANDLE_VALUE)
        {
            cout << "Create Failed! " << GetLastError() << endl;
            break;
        }
        else
        {
            cout << "Create Succeeded! " << endl;
        }

        cout << "Do You Want To Write In It? " << endl;
        cout << "Enter: ";
        cin >> yn;

        switch(tolower(yn[0]))
        {
        case 'y':
            cout << "Write What You Want " << endl;
            cout << "Enter: ";
            cin >> wFile;
            break;

        case 'n':
            break;

        default:
            cout << "Invalid Character ";
            break;
        }

        WriteFile(
        cFile,
        wFile,
        strlen(wFile),
        0,
        NULL
        );

        CloseHandle(cFile);
        break;

    case 6:
        cout << "Enter The PATH of The File You Want To Write In" << endl;
        cout << "Enter: ";
        cin >> path1;

        cFile = CreateFile(
        ((path1).c_str()),
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        );

        if (GetLastError() == 2)
        {
            cout << "There Is No File With That Name! " << endl;
            break;
        }

        cout << "Write What You Want" << endl;
        cout << "Enter: ";
        cin >> wFile;

        if(cFile == INVALID_HANDLE_VALUE)
        {
            cout << "Write Failed! " << GetLastError() << endl;
        }
        else
        {
            cout << "Write Succeeded! " << endl;
        }

        WriteFile(
        cFile,
        wFile,
        strlen(wFile),
        0,
        NULL
        );
        CloseHandle(cFile);
        break;

    case 7:
        cout << "Enter The PATH of The File You Want To Read " << endl;
        cout << "Enter: ";
        cin >> path1;

        cFile = CreateFile(
        ((path1).c_str()),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        );
        if (GetLastError() == 2)
        {
            cout << "There Is No File With That Name! " << endl;
            break;
        }

        if(cFile == INVALID_HANDLE_VALUE)
        {
            cout << "Read Failed! " << GetLastError() << endl;
        }
        ReadFile(
        cFile,
        wFile,
        20,
        0,
        NULL
        );

        cout << "\n" << wFile << endl;

        CloseHandle(cFile);
        break;
    }
    cout << endl;
    return main();
}

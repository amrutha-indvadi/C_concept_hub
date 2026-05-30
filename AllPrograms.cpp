#define _CRT_SECURE_NO_DEPRICATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRICAT

#define BUFFER_SIZE 1000
#define PipeName TEXT("\\\\.\\pipe\\MyPipeName") // Pipe
#pragma comment(lib, "ws2_32.lib") // Socket

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <conio.h>

typedef struct // Realloc for structure
{
	int Number;
	char Letter[50];
}DetailedRecord;

CRITICAL_SECTION  ThreadCritSpace;

void __inline Palindrome() // sequence that reads the same backwards as forwards
{
	int number, original, reversed = 0, reminder;

	printf("Enter a number: ");
	scanf("%d", &number);

	original = number;
	while (number != 0)
	{
		reminder = number % 10; // gets last number
		reversed = reversed * 10 + reminder; // reverse number
		number = number / 10; // remove last digit from num
	}
	if (original == reversed)
		printf("%d is palindrome number\n", reversed);
	else
		printf("%d is not palindrome number\n", original);
}
	 
void __inline CountInteger()
{
	int num;
	int count = 0;

	printf("Enter a number: ");
	scanf("%d", &num);

	while (num != 0)
	{
		count++;
		num /= 10;
	}
	printf("Total number of digits: %d\n", count);
}
	 
void __inline Prime()
{
	int num;
	int IsPrime = 1;

	printf("Enter the number: ");
	scanf("%d", &num);

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			IsPrime = 0;
			break;
		}
	}

	if (IsPrime == 0)
		printf("%d is a not prime number.\n", num);
	else
		printf("%d is a prime number.\n", num);
}

void __inline Sort()
{
	int size, arr[40], temp;

	printf("Enter size of array: ");
	scanf("%d", &size);
	printf("Enter the elements: ");
	for (int i = 1; i <= size; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= size; i++) // ascending
	{
		for (int j = i + 1; j <= size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("Number sortd in ascending order: "); // descending
	for (int i = 1; i <= size; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	for (int i = 1; i <= size; i++)
	{
		for (int j = i + 1; j <= size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("Number sortd in descending order: ");
	for (int i = 1; i <= size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
	 
void __inline Reverse()
{
	int size, arr[50], temp;

	printf("Enter size of array: ");
	scanf("%d", &size);
	printf("Enter the elements: ");
	for (int i = 1; i <= size; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= size; i++)
	{
		for (int j = i + 1; j <= size; j++)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	printf("Reverse number is: ");
	for (int i = 1; i <= size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
	 
void __inline Fibonacci() // 0, 1, 1, 2, 3, 5,...
{
	int num, n1 = 0, n2 = 1, next;

	printf("Enter number of terms: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		printf("%d\t", n1);
		next = n1 + n2;
		n1 = n2;
		n2 = next;
	}
	printf("\n");
}
	 
void __inline Toss()
{
	int toss;
	srand(time(NULL));
	toss = rand() % 2;

	if (toss == 0)
		printf("\n Player1: White \n Player2: Black\n");
	else
		printf("\n Player1: Black \n Player2: white\n");
}
	 
void __inline CurrentTime()
{
	char TimeBuffer[100];
	time_t Time;
	time(&Time);

	struct tm* UtcTime; // UTC time
	UtcTime = gmtime(&Time);
	strftime(TimeBuffer, sizeof(TimeBuffer), "Current date and time (UTC): %d-%b-%Y  %H:%M:%S", UtcTime);
	printf("%s\n", TimeBuffer);

	struct tm* LocalTime; // local time
	LocalTime = localtime(&Time);
	strftime(TimeBuffer, sizeof(TimeBuffer), "Current date and time (Local time): %d-%b-%Y  %H:%M:%S", LocalTime);
	printf("%s\n", TimeBuffer);
}
	 
void __inline Timer()
{
	DWORD StartTime = GetTickCount();
	DWORD EndTime = 10000;
	char Name[50];

	printf("Timer started.\n");
	printf("Enter your name: ");
	while ((GetTickCount() - StartTime) < EndTime)
	{
		if (_kbhit()) // determine if a key has been pressed on the keyboard
		{
			scanf("%s", Name);
			break;
		}
	}
	if ((GetTickCount() - StartTime) == EndTime)
		printf("\nTime out\n");
}
	 
void __inline  EpochDate()
{

	int Date;
	char DateBuffer[100];

	time_t epoch;
	tm sDate;
	memset(&sDate, 0, sizeof(tm));
	tm* pDate;

	printf("Enter date: (Format: yyyymmdd)\n");
	scanf("%d", &Date);

	sDate.tm_year = (Date / 10000) - 1900;
	sDate.tm_mon = ((Date / 100) % 100) - 1;
	sDate.tm_mday = Date % 100;

	epoch = mktime(&sDate);
	printf("Epoch date: %d\n", epoch);

	pDate = localtime(&epoch);
	strftime(DateBuffer, sizeof(DateBuffer), "%Y%m%d %H:%M:%S", pDate);
	printf("Normal date: %s\n", DateBuffer);
}
	 
void __inline ANSI()
{
	printf("Audible noise\a\n");
	printf("Backspace \bText\n");
	printf("Tab\tspace\n");
	printf("Moves to next line\n");
	printf("Moves cusror to column zero\rMOVES\n\n");

	printf("\x1b[30m Hexadecimal\x1b[31m Hexadecimal\x1b[32m Hexadecimal\x1b[33m Hexadecimal\x1b[34m Hexadecimal\x1b[35m Hexadecimal\x1b[36m Hexadecimal\x1b[37m Hexadecimal\x1b[0m\n");
	printf("\x1b[40m Hexadecimal\x1b[41m Hexadecimal\x1b[42m Hexadecimal\x1b[43m Hexadecimal\x1b[44m Hexadecimal\x1b[45m Hexadecimal\x1b[46m Hexadecimal\x1b[47m Hexadecimal\x1b[0m\n");
	printf("\x1b[38;2;153;153;255m Hexadecimal(RGB colours)\x1b[0m\n");
	printf("\x1b[48;2;153;153;255m Hexadecimal(RGB colours)\x1b[0m\n");
	printf("\x1b[1m Hexadecimal(Bold)\x1b[4m Hexadecimal(Underline)\x1b[7m Hexadecimal(swap foreground and background)\x1b[0m\n");
	//printf("\x1b[9;10H Hexadecimal(Move cursor particular row and column)\n");
	//printf("\x1b[1A Hexadecimal(Move cursor up)\n");
	//printf("\x1b[1B Hexadecimal(Move cursor down)\n");
	printf("\x1b[10C Hexadecimal(Move cursor right)\n");
	printf("1234567890\x1b[5D Hexadecimal(Move cursor left)\n");
	//printf("\x1B[H  Hexadecimal(move cursor to page start)\n");
	//printf("\x1b[?25h  Hexadecimal(Show cursor)\n"); 
	//printf("\x1b[?25l  Hexadecimal(Hide cursor)\n");
	//printf("\x1b[2J  Hexadecimal(Screen cleared)\n");
	printf(" Hexadecimal(This line will be cleared)\x1b[2K line cleared\n");
	printf("frist text \x1b[s second text \x1b[u third text\n\n");

	printf("\033[30m Octal\033[31m Octal\033[32m Octal\033[33m Octal\033[34m Octal\033[35m Octal\033[36m Octal\033[37m Octal\033[0m\n");
	printf("\033[40m Octal\033[41m Octal\033[42m Octal\033[43m Octal\033[44m Octal\033[45m Octal\033[46m Octal\033[47m Octal\033[0m\n");
	printf("\033[38;2;153;153;255m Octal(RGB colours)\033[0m\n");
	printf("\033[48;2;153;153;255m Octal(RGB colours)\033[0m\n");
	printf("\033[1m Octal(Bold)\033[4m Octal(Underline)\033[7m Octal(swap foreground and background)\033[0m\n");
	//printf("\033[15;10H Octal(Move cursor particular row and column)\n");
	//printf("\033[1A Octal(Move cursor up)\n");
	//printf("\033[1B Octal(Move cursor down)\n");
	printf("\033[10C Octal(Move cursor right)\n");
	printf("1234567890\033[5D Octal(Move cursor left)\n");
	//printf("\033[H  Octal(move cursor to page start)\n");
	//printf("\033[?25h  Octal(Show cursor)\n"); 
	//printf("\033[?25l  Octal(Hide cursor)\n");
	//printf("\033[2J  Octal(Screen cleared)\n");
	printf(" Octal(This line will be cleared)\033[2K line cleared\n");
	printf("frist text \033[s second text \033[u third text\n\n");

	char Choice[10];
	printf("Enter \'yes\' to open RGB Color Codes Chart\n");
	scanf("%s", Choice);
	if (_stricmp(Choice, "yes") == 0)
		system("START https://www.rapidtables.com/web/color/RGB_Color.html");
}
	 
void __inline ConsoleAPI()
{
	int Choice;
	int Loop = 1;

	//  retrieve a handle to the standard input, standard output, or standard error device associated with a process.
	HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdError = GetStdHandle(STD_ERROR_HANDLE);

	// case 1
	SMALL_RECT PWindowSize = { 0, 0, 79, 49 };

	// case 2
	COORD LargestWindowSize = GetLargestConsoleWindowSize(hStdOut);
	SetConsoleScreenBufferSize(hStdOut, LargestWindowSize);
	SMALL_RECT  LWindowSize = { 0, 0, LargestWindowSize.X - 1, LargestWindowSize.Y - 1 };

	//case 3 & case 4 & case 10
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	WORD SavedAttributes;
	GetConsoleScreenBufferInfo(hStdOut, &ConsoleInfo);

	// case 5
	DWORD DefaultFontSize;

	// case 6
	WCHAR* DefaultFont;
	WCHAR* ChangedFont;

	// case 9
	WORD VirtualKeyCode;

	// case 10
	int ConsoleWidth;
	int Center;
	COORD Coordinate;

	while (Loop)
	{
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("1. Manipulate size of console window\n");
		printf("2. Maximum possible size for console window\n");
		printf("3. Information about console screen buffer\n");
		printf("4. Control foreground and background colors of text displayed in console window\n");
		printf("5. Manipulate font size of text displayed in console window\n");
		printf("6. Manipulate font style of text displayed in console window\n");
		printf("7. Title of a console window\n");
		printf("8. Read character input from a console\n");
		printf("9. Read various input events like keyboard, mouse, and window buffer size changes\n");
		printf("10. Print text in the center\n");
		printf("11. Console background colour\n");
		printf("12. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &Choice);
		printf("\n");

		switch (Choice)
		{
		case 1:
			SetConsoleWindowInfo(hStdOut, TRUE, &PWindowSize);
			break;

		case 2:
			SetConsoleWindowInfo(hStdOut, TRUE, &LWindowSize);
			printf("Largest possible console window size:\n %d columns\n %d rows\n", LargestWindowSize.X, LargestWindowSize.Y);
			break;

		case 3:
			printf("Console Screen Buffer Information:\n");
			printf(" Buffer Size (columns x rows): %d x %d\n", ConsoleInfo.dwSize.X, ConsoleInfo.dwSize.Y);
			printf(" Cursor Position (X, Y): (%d, %d)\n", ConsoleInfo.dwCursorPosition.X, ConsoleInfo.dwCursorPosition.Y);
			printf(" Text Attributes: 0x%04X\n", ConsoleInfo.wAttributes);
			printf(" Window Rect (Left, Top, Right, Bottom): (%d, %d, %d, %d)\n", ConsoleInfo.srWindow.Left, ConsoleInfo.srWindow.Top, ConsoleInfo.srWindow.Right, ConsoleInfo.srWindow.Bottom);
			printf(" Maximum Window Size (columns x rows): %d x %d\n", ConsoleInfo.dwMaximumWindowSize.X, ConsoleInfo.dwMaximumWindowSize.Y);
			break;

		case 4:
			SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | FOREGROUND_RED);
			printf("Dark\n");
			SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
			printf("Bright\n\n");

			SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			printf(" BLACK\n BLUE\n GREEN\n RED\n CYAN (BLUE | GREEN)\n MAGENTA (RED | BLUE)\n BROWN(RED | GREEN)\n LIGHTGRAY (RED | GREEN | BLUE)\n DARKGRAY (FOREGROUND_INTENSITY)\n LIGHTBLUE(BLUE | FOREGROUND_INTENSITY)\n LIGHTGREEN (GREEN | FOREGROUND_INTENSITY)\n LIGHTCYAN (BLUE | GREEN | FOREGROUND_INTENSITY)\n LIGHTRED (RED | FOREGROUND_INTENSITY)\n LIGHTMAGENTA (RED | BLUE | FOREGROUND_INTENSITY)\n YELLOW (RED | GREEN | FOREGROUND_INTENSITY)\n WHITE (RED | GREEN | BLUE | FOREGROUND_INTENSITY)\n");

			SavedAttributes = ConsoleInfo.wAttributes;
			SetConsoleTextAttribute(hStdOut, SavedAttributes);
			break;

		case 5:
			// console window has a single, uniform font size setting that applies to all text displayed within it.
			CONSOLE_FONT_INFOEX FontSize;
			FontSize.cbSize = sizeof(FontSize);

			GetCurrentConsoleFontEx(hStdOut, FALSE, &FontSize);
			DefaultFontSize = FontSize.dwFontSize.Y;
			printf("Defualt Font size: %d\n", FontSize.dwFontSize.Y);

			FontSize.dwFontSize.Y = 25;
			SetCurrentConsoleFontEx(hStdOut, FALSE, &FontSize);
			printf("Changed font size: %d\n", FontSize.dwFontSize.Y);
			Sleep(5000);

			FontSize.dwFontSize.Y = DefaultFontSize;
			SetCurrentConsoleFontEx(hStdOut, FALSE, &FontSize);
			printf("Back to defualt font size: %d\n", FontSize.dwFontSize.Y);
			break;

		case 6:
			// console window has a single, uniform font style setting that applies to all text displayed within it.
			CONSOLE_FONT_INFOEX FontStyle;
			FontStyle.cbSize = sizeof(FontStyle);

			GetCurrentConsoleFontEx(hStdOut, FALSE, &FontStyle);
			DefaultFont = FontStyle.FaceName;
			printf("Default font style: %ls\n", DefaultFont);

			wcscpy_s(FontStyle.FaceName, L"League Spartan Bold");
			SetCurrentConsoleFontEx(hStdOut, FALSE, &FontStyle);
			ChangedFont = FontStyle.FaceName;
			printf("Changed font style: %ls\n", ChangedFont);
			break;

		case 7:
			SetConsoleTitle(TEXT("TITLE: Text User Interface"));
			printf("Console title changed\n");
			break;

		case 8:
			// input
			char BufferRead[100];
			memset(BufferRead, 0, sizeof(BufferRead));
			DWORD Read;

			printf("Enter the text: ");
			ReadConsole(hStdIn, BufferRead, 99, &Read, NULL);
			BufferRead[Read] = '\0';
			wprintf(L"Text entered: %s\n", BufferRead);
			printf("Characters read: %d\n", Read);
			break;

		case 9:
			INPUT_RECORD InputKey;
			DWORD ReadKey;

			printf("Press TAB to to open link for Virtual Key Codes\n");
			printf("Press ESC to exit\n");
			printf("Right click to print\n");
			printf("Press any other key to continue\n");

			SetConsoleMode(hStdIn, ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT);

			ReadConsoleInputW(hStdIn, &InputKey, 1, &ReadKey);
			//InputKey.EventType == KEY_EVENT;
			//InputKey.Event.KeyEvent.bKeyDown;
			VirtualKeyCode = InputKey.Event.KeyEvent.wVirtualKeyCode;

			if (GetKeyState(VK_CAPITAL))
			{
				printf("Caps lock is ON.\n");
			}
			else
			{
				printf("Caps lock is OFF.\n");
			}

			if (VirtualKeyCode == VK_TAB)
			{
				system("START https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes");
			}
			else if (VirtualKeyCode == VK_ESCAPE)
			{
				exit(0);
			}
			else if (GetAsyncKeyState(VK_RBUTTON))
			{
				printf("\033[34m Right mouse button is pressed!\n\033[0m");
			}
			break;

		case  10:
			ConsoleWidth = (ConsoleInfo.srWindow.Right - 10) - (ConsoleInfo.srWindow.Left + 10);
			Center = ConsoleWidth / 2;
			Coordinate = { (SHORT)Center ,0 };
			system("cls");
			SetConsoleCursorPosition(hStdOut, Coordinate);
			printf("Cursor is now at the center!\n");
			Coordinate = { 30,1 };
			SetConsoleCursorPosition(hStdOut, Coordinate);
			printf("Cursor is now at X=30, Y=1!\n");
			Sleep(5000);
			break;

		case 11:
			system("color 31"); // background[1] text[2]
			system("START https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/color");
			break;

		case 12: Loop = 0; break;
		default: printf("Enter valid choice\n"); break;
		}
	}
}
	 
void __inline WriteToFile()
{
	char text[100] = "Hello world";

	FILE* FilePtr1 = fopen("FileName1.txt", "w"); // file type: .txt, .csv,... mode: read (r), write(w), append(a)
	fputc('A', FilePtr1); // character output
	fprintf(FilePtr1, "\n%s (fprintf)\n", text); // formatted output
	fputs("Hello world (fputs)\n", FilePtr1); // string output
	fclose(FilePtr1);

	FILE* FilePtr2 = freopen("FileName2.txt", "w", stdout);
	printf("%s (freopen)\n", text);
	freopen("CON", "w", stdout);

	printf("Text added to file.\n");
}
	 
void __inline ReadFromFile()
{
	char text;
	char Buffer[100];

	FILE* FilePtr1 = fopen("FileName1.txt", "r"); // mode: read (r), write(w), append(a)
	//while (fscanf(FilePtr1, "%s", text) != EOF) // formatted input
	//	printf("%s", Buffer);
	while ((text = fgetc(FilePtr1)) != EOF) // character  input
		printf("%c", text);
	if (fgets(Buffer, sizeof(Buffer), FilePtr1) != NULL) // string input
		printf("%s", Buffer);
	fclose(FilePtr1);

	FILE* FilePtr2 = fopen("FileName2.txt", "r");
	if (fgets(Buffer, sizeof(Buffer), FilePtr2) != NULL)
		printf("%s", Buffer);
	fclose(FilePtr2);
}
	 
void __inline FileMapping()
{
	const char* FileName = "FileName1.txt";
	HANDLE FilePtr = NULL;
	HANDLE FileMap = NULL;
	char* FileView = NULL;
	LARGE_INTEGER FileSize;

	FilePtr = CreateFileA(FileName, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	GetFileSizeEx(FilePtr, &FileSize);
	FileMap = CreateFileMappingW(FilePtr, NULL, PAGE_READWRITE, FileSize.HighPart, FileSize.LowPart, NULL);
	FileView = (char*)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	printf("%s", FileView);

	UnmapViewOfFile(FileView);
	CloseHandle(FileMap);
	CloseHandle(FilePtr);
}
	 
void __inline MemoryAlocation()
{
	char MallocText[100] = "Malloc - Dynamic memory allocation"; // malloc
	char* MallocMemory = (char*)malloc((strlen(MallocText) + 1) * sizeof(char));
	printf("%s\n", MallocText);
	free(MallocMemory);

	char CallocText[100] = "Calloc - Dynamic memory allocation"; // calloc
	char* CallocMemory = (char*)calloc((strlen(CallocText) + 1), sizeof(char));
	printf("%s\n", CallocText);
	free(CallocMemory);

	char* ReallocMemory = NULL; // realloc
	ReallocMemory = (char*)realloc(ReallocMemory, 100 * sizeof(char));
	sprintf(ReallocMemory, "Realloc - Dynamic memory allocation");
	printf("%s\n", ReallocMemory);
	free(ReallocMemory);

	////Type 1:
	//DetailedRecord* Record = NULL; // realloc for structure
	//int InitialBuffer = 0;
	//int ExtendedBuffer = 0;
	//if (InitialBuffer >= ExtendedBuffer)
	//{
	//	DetailedRecord* TempRecord = (DetailedRecord*)realloc(Record, sizeof(DetailedRecord) * (ExtendedBuffer + 10));
	//	if (TempRecord)
	//	{
	//		Record = TempRecord;
	//		memset(Record + ExtendedBuffer, 0, sizeof(DetailedRecord));
	//		ExtendedBuffer += 10;
	//	}
	//	memcpy(Record + InitialBuffer, &Record, sizeof(DetailedRecord));
	//	InitialBuffer++;
	//}

	////Type 2:
	//DetailedRecord* Record = NULL; // realloc for structure
	//int InitialBuffer = 0;
	//int ExtendedBuffer = 0;
	//if (InitialBuffer >= ExtendedBuffer)
	//{
	//	ExtendedBuffer += 10;
	//	DetailedRecord* Record = (DetailedRecord*)realloc(Record, sizeof(DetailedRecord) * ExtendedBuffer);
	//	memset(Record + ExtendedBuffer, 0, sizeof(DetailedRecord));
	//}
	//memcpy(Record + InitialBuffer, &Record, sizeof(DetailedRecord));
	//InitialBuffer++;
}
	 
void __inline MemFunction()
{
	char Buffer1[BUFFER_SIZE];
	char Buffer2[BUFFER_SIZE] = "Memory Manipulation Functions";
	char Buffer3[BUFFER_SIZE];

	memset(Buffer1, 0, sizeof(Buffer1)); // sets specified number of bytes in a memory to particular value
	printf("%s\n", Buffer1);

	memcpy(Buffer1, Buffer2, BUFFER_SIZE); // copies specified number of bytes from source to destination
	printf("%s\n", Buffer1);

	memmove(Buffer3, Buffer2, BUFFER_SIZE); // copies specified number of bytes from source to a destination
	printf("%s\n", Buffer3);

	if (memcmp(Buffer1, Buffer2, BUFFER_SIZE) == 0) // compares specified number of bytes from two memory locations
		printf("both the buffer are same\n");
	else
		printf("both the buffer are not same\n");

	char* FirstOccurrence = (char*)memchr(Buffer1, 'a', BUFFER_SIZE); // locate first occurrence of specific character
	printf("%s\n", FirstOccurrence);
}
	 
void __inline PipeServer()
{
	char Buffer[BUFFER_SIZE];
	DWORD Write, Read;

	HANDLE HPipe = CreateNamedPipeW(PipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, BUFFER_SIZE, BUFFER_SIZE, 0, NULL);
	BOOL Success = ConnectNamedPipe(HPipe, NULL);

	sprintf(Buffer, "Server says hi\n");
	Success = WriteFile(HPipe, Buffer, BUFFER_SIZE, &Write, NULL);
	Success = ReadFile(HPipe, Buffer, BUFFER_SIZE, &Read, NULL);
	printf("%s", Buffer);

	FlushFileBuffers(HPipe);
	DisconnectNamedPipe(HPipe);
	CloseHandle(HPipe);
}
	 
void __inline PipeClient()
{
	BOOL Success;
	DWORD Read, Write;
	char Buffer[BUFFER_SIZE];

	while (!WaitNamedPipeW(PipeName, NMPWAIT_WAIT_FOREVER))
		printf("Waiting for server.\n");
	HANDLE HPipe = CreateFileW(PipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	Success = ReadFile(HPipe, Buffer, BUFFER_SIZE, &Read, NULL);
	printf("%s", Buffer);
	sprintf(Buffer, "Client says hi\n");
	Success = WriteFile(HPipe, Buffer, BUFFER_SIZE, &Write, NULL);

	FlushFileBuffers(HPipe);
	CloseHandle(HPipe);
}
	 
void __inline SocketServer()
{
	WSADATA wsa;
	struct sockaddr_in ServerAddress, ClientAddress;
	SOCKET ServerSocket, ClientSocket;
	int ClientAddressLength = sizeof(struct sockaddr_in);

	char Message[100];
	char Buffer[1000];

	WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize socket
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0); // Create socket

	// Socket address structure
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_addr.s_addr = INADDR_ANY;
	ServerAddress.sin_port = htons(8888);

	bind(ServerSocket, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)); // Bind socket
	listen(ServerSocket, 10); // Listen for incoming connections
	ClientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddress, &ClientAddressLength); // Accept incoming connection
	printf("Connected to client.\n");

	while (1)
	{
		printf("Enter message: ");
		fgets(Message, sizeof(Message), stdin);
		send(ClientSocket, Message, strlen(Message), 0);

		int data_received = recv(ClientSocket, Buffer, sizeof(Buffer) - 1, 0);
		if (data_received > 0)
		{
			Buffer[data_received] = '\0';
			printf("Client message: %s\n", Buffer);
		}
	}

	closesocket(ClientSocket);
	closesocket(ServerSocket);
	WSACleanup();
}
	 
void __inline SocketClient()
{
	WSADATA wsa;
	struct sockaddr_in ServerAddress;
	SOCKET ClientSocket;

	char Message[100];
	char Buffer[1000];

	WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize socket
	ClientSocket = socket(AF_INET, SOCK_STREAM, 0); // Create socket

	// Prepare socket address structure
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_addr.s_addr = inet_addr("192.168.50.57");
	ServerAddress.sin_port = htons(8888);

	connect(ClientSocket, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)); // Connect to server
	printf("Connected to server.\n");

	while (1)
	{
		int data_received = recv(ClientSocket, Buffer, sizeof(Buffer) - 1, 0);
		if (data_received > 0)
		{
			Buffer[data_received] = '\0';
			printf("server message: %s\n", Buffer);
		}
		printf("Enter message: ");
		fgets(Message, sizeof(Message), stdin);
		send(ClientSocket, Message, strlen(Message), 0);
	}

	closesocket(ClientSocket);
	WSACleanup();
}
	 
void __inline ReadLineUsingScanf()
{
	char ch1[100];
	char ch2[100];
	char ch3[100];

	printf("Enter a word and then a line\n");
	scanf("%s\n", ch1);
	scanf("%[^\n]%*c", ch2);  //use scanf("\n"); before the last statement.
	fgets(ch3, BUFFER_SIZE, stdin);

	printf("Word: %s\n", ch1);
	printf("Line: %s\n", ch2);
	printf("Line(fgets): %s\n", ch3);
}
	 
void __inline DriveSpace()
{
	_In_ LPCTSTR Drive = L"C:\\";
	ULARGE_INTEGER FreeBytesAvailableToCaller, TotalNumberOfBytes, TotalNumberOfFreeBytes;

	GetDiskFreeSpaceEx(Drive, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes);

	double TotalSpaceGB = (double)TotalNumberOfBytes.QuadPart / (1024.0 * 1024.0 * 1024.0);
	double FreeSpaceGB = (double)TotalNumberOfFreeBytes.QuadPart / (1024.0 * 1024.0 * 1024.0);
	double FreeSpaceAvailableGB = (double)FreeBytesAvailableToCaller.QuadPart / (1024.0 * 1024.0 * 1024.0);

	printf("Disk Information for drive %s:\n", Drive);
	printf("Total space: %.2f GB\n", TotalSpaceGB);
	printf("Free space: %.2f GB\n", FreeSpaceGB);
	printf("Free space available to caller: %.2f GB\n", FreeSpaceAvailableGB);
}
	 
void __inline ZipFolder()
{
	char Command[1000];
	const char* FolderPath = "C:\\Users\\Administrator\\source\\repos\\AllPrograms\\AllPrograms\\Notes";
	const char* ZipPath = "C:\\Users\\Administrator\\source\\repos\\AllPrograms\\AllPrograms\\Notes.zip";

	sprintf(Command, "powershell Compress-Archive -Path \"%s\" -DestinationPath \"%s\"", FolderPath, ZipPath);
	system(Command);
	printf("File zipped successfully using PowerShell.\n");
}
	 
void __inline UnzipFolder()
{
	char Command[1000];
	const char* ZipPath = "C:\\Users\\Administrator\\source\\repos\\AllPrograms\\AllPrograms\\Notes.zip";
	const char* ExtractPath = "C:\\Users\\Administrator\\source\\repos\\AllPrograms\\AllPrograms";

	sprintf(Command, "powershell -command \"Expand-Archive -Path \\\"%s\\\" -DestinationPath \\\"%s\\\" -Force\"", ZipPath, ExtractPath);
	system(Command);
	printf("File unzipped successfully using PowerShell.\n");
}

char* ReadLine(const char* Buffer, int Line)
{
	int currentLine = 1;
	const char* lineStart = Buffer;
	const char* lineEnd = NULL;

	while (*lineStart != '\0')
	{
		lineEnd = strchr(lineStart, '\n');
		if (currentLine == Line)
		{
			int lineLength;
			if (lineEnd != NULL)
				lineLength = lineEnd - lineStart;
			else
				lineLength = strlen(lineStart);

			char* result = (char*)malloc(lineLength + 1);
			strncpy(result, lineStart, lineLength);
			result[lineLength] = '\0';
			return result;
		}
		if (lineEnd == NULL)
			break;

		lineStart = lineEnd + 1;
		currentLine++;
	}
	return NULL;
}

DWORD WINAPI MultiThread(LPVOID parameter)
{
	int number = 1;

	EnterCriticalSection(&ThreadCritSpace);

	for (int i = 1; 1 <= 2; i++)
	{
		printf(" Thread function: %d\n", number);
		number++;
		if (number == 3)
			break;
		//Sleep(100);
	}

	LeaveCriticalSection(&ThreadCritSpace);

	return 0;
}

// MAIN FUNCTION ---------------------------------------------------------------------------------------------

int main()
{
	int choice;

	char Text[100] = "Hello World \nMy name is Amrutha\n";
	char* SecondLine;
	char letter = 'A';

	while (1)
	{
		Sleep(5000);

		printf("\033[1m\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
		printf("1. Check whether  a number is palindrome or not.\n");
		printf("2. Count number of digits in an integer.\n");
		printf("3. Check whether a number prime or not.\n");
		printf("4. Sort elements in ascending and descending order.\n");
		printf("5. Reverse the number.\n");
		printf("6. Fibonacci series upto N terms.\n");
		printf("7. Toss a coin (random number generator).\n");
		printf("8. Current date and time.\n");
		printf("9. Timer for 10 sec.\n");
		printf("10. Date in epoch format.\n");
		printf("11. ANSI escape code.\n");
		printf("12. Windows console API functions.\n");
		printf("13. Write to file (File Handling).\n");
		printf("14. Read from file (File Handling).\n");
		printf("15. Read from file (File Mapping).\n");
		printf("16. Dynamic memory allocation.\n");
		printf("17. Memory Manipulation Functions.\n");
		printf("18. Pipe server.\n");
		printf("19. Pipe client.\n");
		printf("20. Socket server.\n");
		printf("21. Socket client.\n");
		printf("22. Read line using scanf function.\n");
		printf("23. Drive size and total available size.\n");
		printf("24. Zip folder.\n");
		printf("25. Unzip folder.\n");
		printf("26. Read a single line.\n");
		printf("27. Multi thread function.\n");
		printf("28. Console full screen.\n");
		printf("29. Website link\n");
		printf("30. Exit.\n");
		printf("\033[1m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1: Palindrome(); break;
		case 2: CountInteger(); break;
		case 3: Prime(); break;
		case 4: Sort(); break;
		case 5: Reverse(); break;
		case 6: Fibonacci(); break;
		case 7: Toss(); break;
		case 8: CurrentTime(); break;
		case 9: Timer(); break;
		case 10: EpochDate(); break;
		case 11: ANSI(); break;
		case 12: ConsoleAPI(); break;
		case 13: WriteToFile(); break;
		case 14: ReadFromFile(); break;
		case 15: FileMapping(); break;
		case 16: MemoryAlocation(); break;
		case 17: MemFunction(); break;
		case 18: PipeServer(); break;
		case 19: PipeClient(); break;
		case 20: SocketServer(); break;
		case 21: SocketClient(); break;
		case 22: ReadLineUsingScanf(); break;
		case 23: DriveSpace(); break;
		case 24: ZipFolder(); break;
		case 25: UnzipFolder(); break;
		case 26:
			SecondLine = ReadLine(Text, 2);
			printf("%s\n", SecondLine);
			break;
		case 27:
			HANDLE Thread;
			DWORD ThreadID;
			Thread = CreateThread(NULL, 0, MultiThread, NULL, 0, &ThreadID);

			memset(&ThreadCritSpace, 0, sizeof(CRITICAL_SECTION));
			InitializeCriticalSection(&ThreadCritSpace);
			EnterCriticalSection(&ThreadCritSpace);

			for (int i = 1; 1 <= 2; i++)
			{
				printf(" Main function: %c\n", letter);
				letter++;
				if (letter == 'C')
					break;
				//Sleep(70);
			}

			LeaveCriticalSection(&ThreadCritSpace);

			WaitForSingleObject(Thread, INFINITE);

			CloseHandle(Thread);
			break;
		case 28:
			ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
			break;
		case 29:
			system("START https://www.microsoft.com/en-in/microsoft-365/microsoft-office");
			break;

		case 30: exit(0); break;
		default:
			printf("Enter valid choice!\n");
		}
	}
	return 0;
}
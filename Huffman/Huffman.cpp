// Huffman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Huffman.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = {10,4,6,7,8,9,34,6,7,8};
	huffmanBuild(a, 10);
	Sleep(200000);
}


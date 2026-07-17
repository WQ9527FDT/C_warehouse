#include <stdio.h>
#include <windows.h>
int main(int chave, char* chav[])
{
		FILE* textn = fopen(chav[1], "rb");
		FILE* copyn = fopen("QQ", "wb");
		if (NULL == textn || NULL == copyn) return -1;
		char c;
		int r;
		while (1)
		{
			r = fread(&c, 1, 1, textn);
			if (r < 1)break;
			c ^= 0x34;
			fwrite(&c, 1, 1, copyn);

		}
		fclose(textn);
		fclose(copyn);
		Sleep(1000);
		//   删除需要加密的原文件
		printf("删除需要加密的原文件\n");
		DeleteFileA(chav[1]);
		Sleep(1000);



		//   改名加密后的文件
		printf("改名加密后的文件\n");
		MoveFileA("QQ",chav[1]);
		Sleep(1000);


		printf("加密成功\n");
	














}

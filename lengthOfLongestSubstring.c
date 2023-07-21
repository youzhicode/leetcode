#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char * s)
{
	
	int len = strlen(s);
	char* long_str = (char *)malloc(len + 1);
	for(int i=0; i<len; i++) {
		long_str[i++] = '\0';
	}
	int longest = 0;
	int longer = 0;
	for (int j=0; j<len; j++) {
		long_str[0] = s[j];
		longer = 1;
		for (int k=j+1;k<len; k++) {
			for (int l=0; l<longest; l++) {
				if (long_str[l] == s[k]) {
					break;
				} else {
					++longer;
				}	
			}
			if (longer > longest) {
				long_str[longest] = s[k];
				++longest;
				break;
			}

		}	
	}



	return 0;
}

int main()
{


	char* str = "pwwkew";
	
	lengthOfLongestSubstring(str);
	return 0;
}

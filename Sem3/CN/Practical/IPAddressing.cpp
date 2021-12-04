// 2. Write the program IP addressing by taking the
// IP address as input and print the corresponding
// class, Net –ID and Host-ID.

#include<stdio.h>
#include<string.h>

char findClass(char str[]) {
	char arr[4];
	int i = 0;
	while (str[i] != '.') {
		arr[i] = str[i];
		i++;
	}
	i--;
	int ip = 0, j = 1;
	while (i >= 0) {
		ip = ip + (str[i] - '0') * j;
		j = j * 10;
		i--;
	}

	// Class A
	if (ip >=1 && ip <= 126)
		return 'A';
	// Class B
	else if (ip >= 128 && ip <= 191)
		return 'B';
	// Class C
	else if (ip >= 192 && ip <= 223)
		return 'C';

	// Class D
	else if (ip >= 224 && ip <= 239)
		return 'D';

	// Class E
	else
		return 'E';
}

void separate(char str[], char ipClass) {
	// Initializing network and host array to NULL
	char network[12], host[12];
	for (int k = 0; k < 12; k++)
		network[k] = host[k] = '\0';
	if (ipClass == 'A') {
		int i = 0, j = 0;
		while (str[j] != '.')
			network[i++] = str[j++];
		i = 0;
		j++;
		while (str[j] != '\0')
			host[i++] = str[j++];
		printf("Network ID is %s\n", network);
		printf("Host ID is %s\n", host);
	}
	else if (ipClass == 'B') {
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 2) {
			network[i++] = str[j++];
			if (str[j] == '.')
				dotCount++;
		}
		i = 0;
		j++;
		while (str[j] != '\0')
			host[i++] = str[j++];

		printf("Network ID is %s\n", network);
		printf("Host ID is %s\n", host);
		}
	else if (ipClass == 'C') {
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 3) {
			network[i++] = str[j++];
			if (str[j] == '.')
				dotCount++;
		}
		i = 0;
		j++;
		while (str[j] != '\0')
			host[i++] = str[j++];
		printf("Network ID is %s\n", network);
		printf("Host ID is %s\n", host);
		}
	else
		printf("In this Class, IP address is not divided into Network and Host ID\n");
}

// Driver function is to test above function
int main() {
	char str[] = "192.226.12.11";
	char ipClass = findClass(str);
	printf("\nGiven IP address \nbelongs to Class %c\n", ipClass);
	separate(str, ipClass);
	return 0;
}

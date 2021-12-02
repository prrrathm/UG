#include<stdio.h>

int main() {
    printf("CRC-12 Program with noiseless Channel\n\n");
	printf("Transmitter Side:\n");
	//Frame 
    // Frame Size = n = 12
    printf("Size of Transmission : 12");
	int n = 12;
    int data[n];
	printf("\nEnter Frame String: ");
	for (int i=0;i<n;i++)
		scanf("%d",&data[i]);
	
	//Generator
	int g;
	printf("\nEnter Generator Size: ");
	scanf("%d",&g);
	int generator[g];
	do {
		printf("\nEnter Generator: ");
		for (int i=0;i<g;i++)
			scanf("%d",&generator[i]);	
	} while (generator[0]!=1);

	//Generator Matrix
	printf("\nThe Generator Matrix: ");
	for (int i=0;i<g;i++)
		printf("%d ",generator[i]);
	
	// Append size = n+g-1
	int append[n+g-1];
	for (int i=0;i<(n+g-1);i++) {
		if (i<n)
			append[i]=data[i];
		else
			append[i]=0;
	}
	
	printf("\nThe Appended String: ");
	for (int i=0;i<n+g-1;i++) {
		printf("%d ",append[i]);
        }
	
	for (int j=0;j<n;j++) {
		if (append[j]==1) {
			for (int i=0;i<g;i++)
				append[j+i]=append[j+i]^generator[i];
            }
        else {
			for (int i=0;i<g;i++)
				append[j+i]=append[j+i]^0;
            }
        }

	printf("\nCRC value: ");
	for (int i=n; i<n+g-1; i++)
		printf("%d ",append[i]);
	
	for (int i=0;i<n;i++)
		append[i]=data[i];
	
    printf("\nTransmitted Data: ");
	for (int i=0;i<n+g-1;i++)
		printf("%d ",append[i]);
	
	printf("\n\nReciever Side: ");
	for (int j=0;j<n;j++) {
		if (append[j]==1)
			for (int i=0;i<g;i++)
				append[j+i]=append[j+i]^generator[i];
		else
			for (int i=0;i<g;i++)
				append[j+i]=append[j+i]^0;
	}
	int c=0;
	for (int i=0;i<n+g-1;i++)
			c+=append[i];
	if (c==0)
		printf("The data transmitted matches with the original data!\n");
	else
		printf("The data transmitted does not matches with the original data!\n");
	printf("\n");
	return 0;
}

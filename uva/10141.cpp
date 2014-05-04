#include <cstdio>
#include <cstring>

void readLine(char *line, int len) {
	memset(line, 0, len);
	gets(line);
}
void copyStr(char *dest, char *src, int len) {
	memset(dest, 0, len);
	strcpy(dest, src);
}
int main() {
	//freopen("input.txt", "r", stdin);

	const int lineLength = 128;
	char line[lineLength], bestOfferName[lineLength], offerName[lineLength];
	int reqs, props, bestOfferReqs, offerReqs, testId = 0;
	float bestOfferPrice, offerPrice;

	do {
		testId++;
		reqs = 0;
		props = 0;
		bestOfferReqs = -1;
		bestOfferPrice = -1;
		memset(bestOfferName, 0, lineLength);

		readLine(line, lineLength);
		sscanf(line, "%d %d", &reqs, &props);

		if ((reqs != 0) || (props != 0)) {
			for (int i = 0; i < reqs; i++)
				readLine(line, lineLength);

			for (int i = 0; i < props; i++) {
				readLine(line, lineLength);
				copyStr(offerName, line, lineLength);
				readLine(line, lineLength);
				sscanf(line, "%f %d", &offerPrice, &offerReqs);
				for (int j = 0; j < offerReqs; j++)
					readLine(line, lineLength);
				if (offerReqs > bestOfferReqs) {
					copyStr(bestOfferName, offerName, lineLength);
					bestOfferReqs = offerReqs;
					bestOfferPrice = offerPrice;
				} else if ((offerReqs == bestOfferReqs) && (offerPrice < bestOfferPrice)) {
					copyStr(bestOfferName, offerName, lineLength);
					bestOfferReqs = offerReqs;
					bestOfferPrice = offerPrice;
				}
			}
			printf("RFP #%d\n%s\n\n", testId, bestOfferName);
		}
	} while ((reqs != 0) || (props != 0));
	return 0;
}

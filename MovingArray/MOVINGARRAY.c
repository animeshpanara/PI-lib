#include "movingArray.h"
float movingArray[movingArrayNumber][movingArrayFrequency];
float sum[movingArrayNumber] = {0};
int index[movingArrayNumber] = {0};
int flags[movingArrayNumber]={0};

float movingArrayOut(int i,float in) {
	index[i]=(index[i]+1)%movingArrayFrequency;
	if(flags[i]==1)
	{	
		sum[i]-=movingArray[i][index[i]];
		movingArray[i][index[i]] = in;
		sum[i]+=in;
		return sum[i]/movingArrayFrequency;
	}
	if(index[i]==movingArrayFrequency-1)
	flags[i]=1;
	movingArray[i][index[i]] = in;
	sum[i]+=in;
	return sum[i]/index[i];
}


include "PatternContainer.h"
static bool PatternContainer::sortPatternUnit(const PatternUnit PU_A,const PatternUnit PU_B)
{
	return PU_A.getValue()>PU_B.getValue();
}
void PatternContainer::evaluatePatternValue()
{
			//cout<<PC.getPattern().size()<<endl;
	for(int i=0;i<pattern.size();i++)
	{
		for(int j=0;j<SMS.size();j++)
		{
			string temp;
			temp.append(" ");
			temp.append(pattern[i].getPatternName());
			temp.append(" ");
			if(SMS[j].find(temp)!=string::npos)
			{
				pattern[i].incNormalPatternFreq();
			}	
		}
	}
	for(int i=0;i<pattern.size();i++)
		pattern[i].calValue();

}
vector<PatternUnit> PatternContainer::getChoosePattern()
{
	return choosePattern;
}
void PatternContainer::SortPattern(int numOfPattern)
{
			//vector<PatternUnit>::iterator PatternIterator;
	sort(pattern.begin(),pattern.end(),sortPatternUnit);
	if(numOfPattern>0)
	{				
		for(int i=0;i<numOfPattern;i++)
		{
			choosePattern.push_back(pattern[i]);
		}				
	}
}
vector<PatternUnit> PatternContainer::getPattern()
{
	return pattern;
}
int PatternContainer::findAndIncPatternFreq(PatternUnit PU)
{			
	bool isFind=false;
	for(int i=0;i<pattern.size();i++)
	{
		if(pattern[i]==PU)
		{
			pattern[i].incSpamPatternFreq();
			isFind=true;
			return pattern[i].getSpamFrequency();
		}
	}
	if(!isFind)
	{
		return 0;
	}
	return 0;
}
int PatternContainer::getPatternLength()
{
	return lengthOfPattern;  
}
void PatternContainer::setPatternVector(vector<PatternUnit> PC)
{
	pattern=PC;
}
bool PatternContainer::addPatternUnit(PatternUnit PU)
{
	pattern.push_back(PU);
			// cout<<pattern.size()<<endl;
			// char a;
			// cin>>a;
	return 1;
}
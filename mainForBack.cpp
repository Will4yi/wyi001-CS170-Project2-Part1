#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////


int ForwardSearch(int n, int BV, int TBV, int BI, int* A, int* BA)
{

	//Variables
	int tempindex = 0;
	int counter = 1;
	int FeatureCounter = 0;
	int FinalValue = -1;
	int TempFinalValue = -1;


	//Initialize BA array
	for (int i = 0; i < n + 1; i++) {
		BA[i] = 0;
	}

	// Initial Case
	cout << "Using no features and random evaluation, I get an accuracy of ";
	cout << A[0];
	cout << "%" << endl << endl;

	//Best values
	BA[0] = 0;
	BI = 0;
	BV = A[0];
	TBV = BV;
	cout << "Beginning search." << endl << endl;



	//Begin Searching features
	for (int j = 0; j < n; j++) {
		TempFinalValue = -1;

		for (int i = 0; i < n - j; i++)
		{

			//Output features
			cout << "	Using feature(s) {";
			for (int l = 1; l < BI + 1; l++)
			{
				if (j != 0)
				{
					cout << BA[l] << ",";
				}
			}

		label:
			for (int m = 0; m < n; m++)
			{
				if (BA[m + 1] == i + 1 + FeatureCounter)
				{

					FeatureCounter++;
					goto label;
				}

			}

			cout << i + 1 + FeatureCounter << ",";
			cout << "} accuracy is " << A[counter] << "%" << endl;

			//Check if best
			if (A[counter] > BV)
			{
				BV = A[counter];

				if (BV > FinalValue)
				{
					FinalValue = BV;
					TempFinalValue = 1;
				}


				BA[j + 1] = i + 1 + FeatureCounter;
			}
			counter++;
			FeatureCounter = 0;

		}

		if (TempFinalValue != 1)
		{
			break;
		}


		//Check if best changed and incriment if yes
		if (BV != TBV && BV > TBV)
		{
			TBV = BV;
			BI++;
		}

		//Change BA incase there wasn't best
		if (BA[j + 1] == 0)
		{

			BA[j + 1] = tempindex;
			//cout << "Test BA " << BA[1] << endl; //Test
		}

		//Output best feature
		cout << endl << "Feature set {";
		for (int i = 1; i < BI + 1; i++)
		{

			cout << BA[i] << ",";
		}
		cout << "} was best, accuracy is " << BV << "%" << endl << endl;

		TempFinalValue = -1;
	}

	cout << endl << "Finished Forward search!!! The best Feature subset is {";
	for (int i = 1; i < BI + 1; i++)
	{

		cout << BA[i] << ",";
	}
	cout << "} which has an accuracy of " << FinalValue << "%" << endl << endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int BackwardSearch(int n, int BV, int TBV, int BI, int* A, int* BA)
{

	//Variables
	int tempindex = 0;
	int counter = 1;
	int FeatureCounter = 0;
	int FinalValue = -1;
	int TempFinalValue = -1;
	int ArraySize = ((n * (n + 1)) / 2 + 1);
	int Remove = -1;
	int index = -1;
	int icounter = 0;
	int flag = -1;
	int jcounter = 1;
	int tempy = -1;

	


	//Initialize BA array
	for (int i = 0; i < n + 1; i++) {
		BA[i] = -1;
	}

	// Initial Case
		if (A[0] > BA[0])
		{
			BA[0] = 0;
			tempindex = 1;
			FinalValue = A[0];
		}

	cout << "Using features {";
	
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ", ";
	}
	cout << "} and random evaluation, I get an accuracy of ";
	cout << A[0];
	cout << "%" << endl << endl;
	cout << "Beginning search." << endl << endl;

	BI = 1;
	//@@
	
	BA[6] = 0;


	//Backwards Output
	for (int k = 0; k < n; k++) //4x
	{
		for (int i = 1; i < n - k + 1; i++) // 4 , 3 , 2 , 1 
		{
			cout << "	Using feature(s) {";
			
			for (int j = 1; j < n + 1 - k ; j++) //Iterate through 234 134 124 123
			{
			
				
					if ((j == counter) || BA[0] == j)
					{

					}
					else {
						cout << j << ", ";

					}
				
			}
			
			counter++;

			icounter++;
			cout << "} accuracy is " << A[icounter] << "%";
			
			//Better Value
			if (A[icounter] > FinalValue)
			{
				FinalValue = A[icounter];
				BA[k + 1] = counter - 1;
				flag = 1;
			}
			cout << endl;


		}
		


		//
		cout << endl << "Feature set {";
		tempy = -1;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (i == BA[j])
				{
					tempy++;
				}
				
			}
			if (tempy != -1)
			{

			}
			else { 
				cout << i << ", "; 
			}
			
		}

		cout << "} was best, accuracy is " << FinalValue << "%" << endl << endl;
		
		counter = 1;
		if (flag == -1)
		{
			break;
		}
		
		flag = -1;
	}
	
	//Finished
	cout << endl << "Finished Backwards search!!! The best Feature subset is {";
	tempy = -1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == BA[j])
			{
				tempy++;
			}

		}
		if (tempy != -1)
		{

		}
		else {
			cout << i << ", ";
		}

	}

	cout << "} which has an accuracy of " << FinalValue << "%" << endl << endl;



	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Variables
	int NumFeatures = -1;
	int Selection = -1;
	int ArraySize = -1;
	int num = -1;
	int BestIndex = -1;
	int BestValue = -1;
	int TempBestValue = -1;
	

	// Prompt User
	cout << "Welcome to William Yi's Feature Selection Algorithm." << endl;
	cout << endl;
	cout << "Please enter total number of features: ";
	
	//Select Number of Features
	cin >> NumFeatures;
	cout << endl;
	num = NumFeatures;

	cout << "Type the number of the algorithm you want to run.";
	cout << endl << endl;
	cout << "1) Forward Selection" << endl;
	cout << "2) Backward Elimination" << endl;
	cout << endl;

	//Select Algorithm
	cin >> Selection;

	// Create array list 
	// Best Array
	int* BestArray = new int[NumFeatures+ 1];

	// 1 + 2 + 3 + 4... summation = (N * (N+1)) /2
	ArraySize = (NumFeatures * (NumFeatures + 1)) / 2 + 1;
	int *Array = new int[ArraySize];

	//Fill in array values
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = (rand() / NumFeatures) % 100;
		//Testing formatting
		//cout << Array[i] << endl;
	}
	
	cout << endl;


	if (Selection == 1)
	{
		ForwardSearch(num, BestValue, TempBestValue, BestIndex, Array, BestArray);
	}

	if (Selection == 2)
	{
		BackwardSearch(num, BestValue, TempBestValue, BestIndex, Array, BestArray);
	}



	delete[] Array;
	cout << endl;
	return 0;
}

///////////////////////////////////////////////////////////////


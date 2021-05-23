// C++ program for implemenbting Shortest Seek Time First disk schedule
#include <bits/stdc++.h>
using namespace std;

// Calculates difference of each track number with the head position
void calculateDifference (int request[], int head, int diff[][2], int n)
{
  for (int i = 0; i < n; i++)
  {
    diff[i][0] = abs(head - request[i]);
  }
}

// Find unaccessed track which is at a minimum distance from the head
int findMIN (int diff[][2], int n)
{
  int index = -1;
  int minimum = 1e9;

  for (int i = 0; i < n; i++ )
  {
    if (!diff[i][1] && (minimum > diff[i][0]))
    {
      minimum = index[i][0];
      index = i;
    }
  }
  return index;
}

void shortestSeekTimeFirst(int request[], int head, int n)
{
  if (n == 0)
  {
    return;
  }

  // create array of objects - class node
  int diff[n][2] = { {0,0} };

  // count total number of seek operations
  int seekCount = 0;

  // stores sequence in which disk access is complete
  int seekSequence[n + 1] = {0};

  for (int i = 0; i < n; i++)
  {
    seekSequence[i] = head;
    calculateDifference(request, head, diff, n)
    int index = findMIN(diff, n);
    diff[index][1] = 1;

    // increase seek count
    seekCount += diff[index][0];

    // current track is now head
    head = request[index];
  }
  seekSequence[n] = head;
  cout << "Total number of seek operations = " << seekCount << end1;
  cout << "Seek sequence is : " << "/n";

  //print the sequence
  for (int i = 0; i < n; i++)
  {
    cout << seekSequence[i] << "/n";
  }

  // Driver Code
  int main()
  {
    int n = 8;
    int proc[n] = { 176, 79, 104, 88, 33, 12, 147, 99};
    shortestSeekTimeFirst(proc, 51, n);

    return 0;
  }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  struct Job {
      int id, deadline, profit;
};
 bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs, int n) {
      sort(jobs.begin(), jobs.end(), compare);

int maxDeadline = 0;
     for (int i=0; i<n; i++) {
           maxDeadline = max(maxDeadline, jobs[i].deadline);
}
vector<int> slots(maxDeadline + 1, -1);

int totalProfit = 0;
int jobsDone = 0;

for (int i=0; i<n; i++) {
for (int j=jobs[i].deadline; j>0; j--) {

if (slots[j] == -1) {
slots[j] = jobs[i].id;
totalProfit += jobs[i].profit;
jobsDone++;
 break;
   }
 }
}
cout << "Job sequence for maximum profit: \n";

for (int i=1; i<=maxDeadline; i++) {
    if (slots[i]!=-1) {
         cout<<slots[i]<<" ";
   }
}
     cout<<"\nTotal profit: "<<totalProfit<<endl;
  }

int main() {

  cout<<"Enter the number of jobs: ";
   int n;
     cin>>n;

      vector<Job> jobs(n);

   cout << "Enter job ID, deadline, and profit for each job:" << endl;

      for (int i=0; i<n; i++) {
         cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
      }
       jobSequencing(jobs, n);
    return 0;
}

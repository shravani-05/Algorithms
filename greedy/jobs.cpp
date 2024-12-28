#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job
{
    int id;
    int deadline;
    int profit;
};
void jobsequencing(vector<Job>& jobs, int maxdeadline){

    sort(jobs.begin(),jobs.end(), [](const Job& a, const Job&b){
        return a.profit>b.profit;
    });

    vector<int> result(maxdeadline,-1);
    int total_profit = 0;
    for(const auto &job : jobs){
        for(int j = min(maxdeadline,job.deadline) -1 ; j >= 0; j--){
            if(result[j] == -1){
                result[j] = job.id;
                total_profit += job.profit;
                break;
            }
        }
    }

    cout<<"Jobs : ";
    for(int i = 0; i < maxdeadline; i++){
        if(result[i] != -1){
            cout<<result[i]<<" ";
        }
    }
    cout<<"\nTotal profit: "<<total_profit;
}
int main(){
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;

    vector<Job> jobs(n);
    cout<<"Enter the Job-id | Job-Deadline | Job-Profit\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Job"<<i+1<<"- ";
        cin>>jobs[i].id>> jobs[i].deadline>> jobs[i].profit;
    }
    
    int maxdeadline = 0;
    for(const auto &job: jobs){
        maxdeadline = max(maxdeadline,job.deadline);
    }

    jobsequencing(jobs,maxdeadline);

}
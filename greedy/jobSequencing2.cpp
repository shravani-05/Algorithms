#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Job
{
    int id;
    int deadline;
    int profit;
};
bool compareJobs(Job a, Job b){
    return a.profit > b.profit;
}
void jobSequencing(vector<Job> jobs,int maxdeadline){
    sort(jobs.begin(),jobs.end(),compareJobs);
    vector<int> result(maxdeadline,-1);
    int totalprofit = 0;

    for(const auto& job : jobs){
        for(int j = min(maxdeadline,job.deadline)-1; j>=0;j--){
            if(result[j] == -1){
                result[j] = job.id;
                totalprofit += job.profit;
                break;
            }
        }
    }

    cout<<"Scheduled Jobs: ";
    for(int i = 0; i < maxdeadline;i++){
        if(result[i] != -1){
            cout<<result[i]<<" ";
        }
    }

    cout<<"\nTotal profit: "<<totalprofit;

}
int main(){
    vector<Job> jobs ={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};

    int maxdeadline = 0;
    for(const auto& job : jobs){
        maxdeadline = max(maxdeadline,job.deadline);
    }

    jobSequencing(jobs,maxdeadline);
    return 0;
}
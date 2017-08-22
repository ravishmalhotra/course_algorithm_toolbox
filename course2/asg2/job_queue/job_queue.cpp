#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (unsigned int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

    void AssignJobs()
    {

        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());


        struct Job_queque {
        int worker;
        long long next_free_time;
        };

        struct Compare //Defining the overload () operator that is used in the Comp(a,b) of priority queque data structure.
        {
            // Sort by reducing free time, if free time is the same, then sort by worker order
            bool operator () (const Job_queque &a, const Job_queque &b) const
            {

                if (a.next_free_time!=b.next_free_time)
                    return b.next_free_time<a.next_free_time;

                else
                    return b.worker<a.worker;

            }
        } ;



        vector<Job_queque> job_queque(num_workers_);
        priority_queue<Job_queque,vector<Job_queque>, Compare> pq; //Defining the priority queque with the correct data structure

        for (int i=0; i<num_workers_; i++)
        {
            //Initiliazing the job queque. Workers work by index, specfiying zero starting time for all threads
            job_queque[i].worker=i;
            job_queque[i].next_free_time=0;
            pq.push(job_queque[i]);

        }

        for (unsigned int i=0; i<jobs_.size(); i++)
        {

            Job_queque pq_push;
            Job_queque pq_top=pq.top(); //Assign current job to the worker on top in the priority queque

            assigned_workers_[i]=pq_top.worker;
            start_times_[i]=pq_top.next_free_time;

            pq.pop();//After the job has been assigned pop it

            pq_push.worker=assigned_workers_[i];//After poping the current worker, add the time when it will be free and push it to the back of queque
            pq_push.next_free_time=start_times_[i]+jobs_[i];

            pq.push(pq_push);

        }


    }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}


//References: https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue/43183813#43183813
//http://www.cplusplus.com/reference/queue/priority_queue/
//http://www.cplusplus.com/reference/algorithm/sort/

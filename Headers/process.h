#ifndef PROCESS_H_   /* Include guard */
#define PROCESS_H_

struct process 
{
    int id;
    int burst;
    int state;
    int priority;
    struct timer *timer;
};

struct process* new_process(int pId, int pBurst,int pPriority);

int get_id(struct process *pProcess);

int get_burst(struct process *pProcess);

int get_state(struct process *pProcess);

int get_priority(struct process *pProcess);

void update_state(struct process *pProcess,int pValue);

const char * to_string(struct process *pProcess);

void print_data(struct process *pProcess);

#endif // PROCESS_H_

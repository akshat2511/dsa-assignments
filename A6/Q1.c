#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int jobID;
    char document[50];
} PrintJob;

typedef struct {
    PrintJob jobs[MAX_QUEUE_SIZE];
    int front;
    int rear;
} PrintSpooler;

void initialize(PrintSpooler *spooler) {
    spooler->front = -1;
    spooler->rear = -1;
}

int isEmpty(PrintSpooler *spooler) {
    return spooler->front == -1;
}

int isFull(PrintSpooler *spooler) {
    return (spooler->rear + 1) % MAX_QUEUE_SIZE == spooler->front;
}

void enqueue(PrintSpooler *spooler, PrintJob job) {
    if (isFull(spooler)) {
        printf("Print spooler is full. Cannot add job.\n");
        return;
    }

    if (isEmpty(spooler))
        spooler->front = spooler->rear = 0;
    else
        spooler->rear = (spooler->rear + 1) % MAX_QUEUE_SIZE;

    spooler->jobs[spooler->rear] = job;
    printf("Job %d added to the print spooler.\n", job.jobID);
}

PrintJob dequeue(PrintSpooler *spooler) {
    if (isEmpty(spooler)) {
        PrintJob emptyJob;
        emptyJob.jobID = -1;
        printf("Print spooler is empty. No jobs to dequeue.\n");
        return emptyJob;
    }

    PrintJob job = spooler->jobs[spooler->front];

    if (spooler->front == spooler->rear)
        spooler->front = spooler->rear = -1;
    else
        spooler->front = (spooler->front + 1) % MAX_QUEUE_SIZE;

    printf("Job %d dequeued from the print spooler.\n", job.jobID);

    return job;
}

void display(PrintSpooler *spooler) {
    if (isEmpty(spooler)) {
        printf("Print spooler is empty.\n");
        return;
    }

    printf("Print Spooler Jobs:\n");
    int i = spooler->front;
    int count = 0;

    while (i != spooler->rear) {
        printf("Job ID: %d, Document: %s\n", spooler->jobs[i].jobID, spooler->jobs[i].document);
        i = (i + 1) % MAX_QUEUE_SIZE;
        count++;
    }

    printf("Job ID: %d, Document: %s\n", spooler->jobs[i].jobID, spooler->jobs[i].document);
    count++;

    printf("Total Jobs in Print Spooler: %d\n", count);
}

int main() {
    PrintSpooler spooler;
    initialize(&spooler);

    int choice;
    PrintJob job;

    printf("Print Spooler Menu:\n");
    printf("1. Add a print job\n");
    printf("2. Dequeue a print job\n");
    printf("3. Display print jobs\n");
    printf("0. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter job ID: ");
                scanf("%d", &job.jobID);
                printf("Enter document name: ");
                scanf("%s", job.document);
                enqueue(&spooler, job);
                break;
            case 2:
                job = dequeue(&spooler);
                if (job.jobID != -1)
                    printf("Dequeued Job: ID=%d, Document=%s\n", job.jobID, job.document);
                break;
            case 3:
                display(&spooler);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}


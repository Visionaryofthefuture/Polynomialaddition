#include <iostream>
using namespace std;

typedef struct node
{
    int coeff;
    int degree;
    struct node *next;
} node;

void init(node **head)
{
    *head = NULL;
    return;
}

void append(node **head, int coeff, int degree)
{
    node *temp = new node;
    temp->coeff = coeff;
    temp->degree = degree;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    node *tracker = *head;
    while (tracker->next)
    {
        tracker = tracker->next;
    }
    tracker->next = temp;
    return;
}

node *add(node **head1, node **head2)
{
    node *p = *head1;
    node *q = *head2;
    node *result = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->degree < q->degree)
        {
            append(&result, q->coeff, q->degree);
            q = q->next;
        }
        else if (p->degree > q->degree)
        {
            append(&result, p->coeff, p->degree);
            p = p->next;
        }
        else
        {
            append(&result, p->coeff + q->coeff, p->degree);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        append(&result, p->coeff, p->degree);
        p = p->next;
    }
    while (q != NULL)
    {
        append(&result, q->coeff, q->degree);
        q = q->next;
    }
    delete(p);
    delete(q);
    return result;
}

void traverse(node **head)
{
    node *tracker = *head;
    while (tracker != NULL)
    {
        cout << tracker->coeff << "x^" << tracker->degree;
        if (tracker->next != NULL)
        {
            cout << " + ";
        }
        tracker = tracker->next;
    }
    cout << endl;
    return;
}

node *subtract(node **head1, node **head2)
{
    node *p = *head1;
    node *q = *head2;
    node *result = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->degree < q->degree)
        {
            append(&result, q->coeff, q->degree);
            q = q->next;
        }
        else if (p->degree > q->degree)
        {
            append(&result, p->coeff, p->degree);
            p = p->next;
        }
        else
        {
            append(&result, p->coeff - q->coeff, p->degree);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        append(&result, p->coeff, p->degree);
        p = p->next;
    }
    while (q != NULL)
    {
        append(&result, q->coeff, q->degree);
        q = q->next;
    }
    delete(p);
    delete(q);
    return result;
}

int main()
{
    node *h1;
    node *h2;
    init(&h1);
    init(&h2);

    int degree;
    cout << "Enter the degree of the first polynomial: ";
    cin >> degree;
    for (int i = 0; i <= degree; ++i)
    {
        int coeff1;
        cout << "Input coefficient for the first polynomial for degree " << i << ": ";
        cin >> coeff1;
        append(&h1, coeff1, i);
    }

    int degree2;
    cout << "Enter the degree of the second polynomial: ";
    cin >> degree2;
    for (int i = 0; i <= degree2; ++i)
    {
        int coeff2;
        cout << "Input coefficient for the second polynomial for degree " << i << ": ";
        cin >> coeff2;
        append(&h2, coeff2, i);
    }

    node *result = add(&h1, &h2);
    traverse(&result);
    node *difference = subtract(&h1, &h2);
    traverse(&difference);
    return 0;
}

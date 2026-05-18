#include <stdio.h>

/* Union definition */
union decision {

    unsigned char flags;

    struct field {

        int your_choice : 1;
        int your_mothers_choice : 1;
        int your_fathers_choice : 1;
        int socially_acceptable : 1;
        int financially_viable : 1;
        int do_you_have_aptitude : 1;
        int do_you_like_it : 1;
        int decision : 1;

    } f;
};

/* Function declarations */
union decision input();

void make_decision(union decision *d);

void print_decision(union decision d);

void print_conclusion_based_on_flags(union decision d);


/* Main function */
int main() {

    union decision d;

    d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}


/* Input function */
union decision input() {

    union decision d;

    int temp;

    printf("Enter your choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_choice = temp;

    printf("Enter your mother's choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_mothers_choice = temp;

    printf("Enter your father's choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_fathers_choice = temp;

    printf("Is it socially acceptable? (1/0): ");
    scanf("%d", &temp);
    d.f.socially_acceptable = temp;

    printf("Is it financially viable? (1/0): ");
    scanf("%d", &temp);
    d.f.financially_viable = temp;

    printf("Do you have aptitude? (1/0): ");
    scanf("%d", &temp);
    d.f.do_you_have_aptitude = temp;

    printf("Do you like it? (1/0): ");
    scanf("%d", &temp);
    d.f.do_you_like_it = temp;

    d.f.decision = 0;

    return d;
}


/* Decision making logic */
void make_decision(union decision *d) {

    d->f.decision =
        d->f.your_choice &&
        d->f.do_you_like_it &&
        d->f.do_you_have_aptitude &&
        d->f.financially_viable;
}


/* Print detailed decision */
void print_decision(union decision d) {

    printf("\n----- DECISION REPORT -----\n");

    if (d.f.decision) {

        printf("You should go ahead with your decision.\n");

        printf("You like it, have aptitude, and it is financially viable.\n");
    }

    else {

        printf("You should rethink your decision.\n");

        if (!d.f.do_you_like_it)
            printf("- You do not like it.\n");

        if (!d.f.do_you_have_aptitude)
            printf("- You may not have aptitude for it.\n");

        if (!d.f.financially_viable)
            printf("- It may not be financially viable.\n");
    }
}


/* Print interpretation using flags value */
void print_conclusion_based_on_flags(union decision d) {

    printf("\nFlags value = %u\n", d.flags);

    if (d.flags > 200)
        printf("Excellent overall alignment.\n");

    else if (d.flags > 100)
        printf("Moderate confidence in the decision.\n");

    else
        printf("Weak support for the decision.\n");
}
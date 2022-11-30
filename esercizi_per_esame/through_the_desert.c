#include <stdio.h>
#include <string.h>

enum event {FUEL, LEAK, GAS, MECHANIC, GOAL};

typedef struct
{
    int fuel;
    int leaks;
    int consumption;

} Vehicle;

typedef struct
{
    enum event e;
    int km;
    int consumption;

} Journey;

Vehicle v;

float calc (Journey jour[], int A, int B)
{
    float consumption = 0;

    for (int i = A; i < B; i++)
    {
        if (jour[i].e == FUEL)
        {
            v.consumption = jour[i].consumption;
        }
        if (jour[i].e == LEAK)
        {
            //v.consumption += 100;
            v.leaks += 1;
        }
        if (jour[i].e == MECHANIC)
        {
            v.leaks = 0;
        }

        consumption += (jour[i + 1].km - jour[i].km) * (v.consumption / (float)100 + v.leaks);
        //printf ("TEMP: %f\n", consumption);

    }

    return consumption;
}

float solve (Journey jour[], int n)
{
    int A = 0, B = 0;
    float tank = 0, max_tank = 0;
    for (int i = 0; i < n; i++)
    {
        if (jour[i].e == GAS || jour[i].e == GOAL)
        {
            A = B;
            B = i;
            tank = calc (jour, A, B);
            //printf ("TEMP TANK: %f\n", tank);

            if (tank >= max_tank) max_tank = tank;
        }
    }
    return max_tank;
}

int main ()
{
    /*
    Journey jour[10];

    jour[0].consumption = 10;
    jour[0].e = FUEL;
    jour[0].km = 0;
    
    jour[1].consumption = 0;
    jour[1].e = GOAL;
    jour[1].km = 100;

    printf ("Risultato: %2.f\n", solve (jour, 2));
    */
    Journey jour[50];
    int n = 0;
    char buffer[128];
    int km;
    int consumption;
    enum e;
    char e_buff[32];
    char e_buff2[32];

   while (1)
   {
        fgets (buffer, 127, stdin);

        if (strcmp (buffer, "0 Fuel consumption 0\n") == 0) break;

        sscanf (buffer, "%d %s", &km, e_buff);

        if (strcmp (e_buff, "Fuel") == 0)
        {
            sscanf (buffer, "%d %s %s %d", &km, e_buff, e_buff2, &consumption);
            jour[n].km = km;
            jour[n].consumption = consumption;
            jour[n].e = FUEL;
        }
        if (strcmp (e_buff, "Leak") == 0)
        {
            sscanf (buffer, "%d", &km);
            jour[n].km = km;
            jour[n].consumption = 0;
            jour[n].e = LEAK;
        }
        if (strcmp (e_buff, "Gas") == 0)
        {
            sscanf (buffer, "%d", &km);
            jour[n].km = km;
            jour[n].consumption = 0;
            jour[n].e = GAS;    
        }
        if (strcmp (e_buff, "Mechanic") == 0)
        {
            sscanf (buffer, "%d", &km);
            jour[n].km = km;
            jour[n].consumption = 0;
            jour[n].e = MECHANIC;    
        }
        if (strcmp (e_buff, "Goal") == 0)
        {
            sscanf (buffer, "%d", &km);
            jour[n].km = km;
            jour[n].consumption = 0;
            jour[n].e = GOAL;    
        }
        n++;        
   }

    /*
   for (int i = 0; i < n; i++)
   {
        printf ("%d %d %d\n", jour[i].km, jour[i].e, jour[i].consumption);
   }
   */
    printf ("RISULTATO: %.3f\n", solve (jour, n));

    return 0;
}
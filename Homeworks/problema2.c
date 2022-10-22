#include <stdio.h>
#include <stdlib.h>

struct Joint
{
    int value;
    int index;
};

struct Joint* build_joints (int *v, int n)
{
    struct Joint *joints = malloc (sizeof(int) * 2 * n);
    struct Joint *j = joints;

    if (joints == NULL)
    {
        printf ("Error in build joints (Malloc failed !)\n");
        return NULL;
    }

    for (int i = 0; i < n; j += 1, i++)
    {
        (*j).value = v[i];
        (*j).index = i;
    }

    return joints;
}

void print_joints (struct Joint *joints, int n)
{
    struct Joint *j = joints;
    
    for (int i = 0; i < n; j += 1, i++)
    {
        printf ("[%d, %d]  ", (*j).value, (*j).index);
    }
    printf ("\n");
}

void free_joints (struct Joint *joints)
{
    free(joints);
}

struct Joint * build_joints_frJ (struct Joint* joints, int n)
{
    struct Joint *j = malloc (sizeof(struct Joint) * n);

    if (j == NULL)
    {
        printf ("Error in built_joints_frJ (Malloc failed)\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        j[i].value = joints[i].value;
        j[i].index = joints[i].index;
    }

    return j;
}

void combine (struct Joint *joints, int l, int q, int r)
{
    int il = 0, ir = 0;
    int nl = q - l + 1, nr = r - (q + 1) + 1;

    struct Joint *jl = build_joints_frJ (joints + l, nl);
    struct Joint *jr = build_joints_frJ (joints + q + 1, nr);


    while (il < nl && ir < nr)
    {
        if (jl[il].value <= jr[ir].value)
        {
            joints[l + il + ir].value = jl[il].value;
            joints[l + il + ir].index = jl[il].index;

            il++;
        }
        else
        {
            joints[l + il + ir].value = jr[ir].value;
            joints[l + il + ir].index = jr[ir].index;

            ir++;
        }
    }

    while (il < nl)
    {
        joints[l + il + ir].value = jl[il].value;
        joints[l + il + ir].index = jl[il].index;

        il++;
    }

    while (ir < nr)
    {
        joints[l + il + ir].value = jr[ir].value;
        joints[l + il + ir].index = jr[ir].index;

        ir++;        
    }

    free_joints (jl);
    free_joints (jr);
}

void merge_sort (struct Joint *j, int l, int r)
{
    if (l != r)
    {
        int q = (l + r) / 2;

        merge_sort (j, l, q);
        merge_sort (j, q + 1, r);
        combine (j, l, q, r);
    }
}

int * solve (int *input, int n)
{
    struct Joint *j = build_joints (input, n);

    merge_sort (j, 0, n - 1);

    int *output = malloc (sizeof(int) * n);

    if (output == NULL)
    {
        printf ("Error in solve (Malloc failed !)\n");
        return NULL;
    }

    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && j[i].value == j[i + 1].value)  
            count++;
        else
            count = 0;

        output[j[i].index] = i + 1 + count;
    }

    free_joints (j);

    return output;
}





int main ()
{
    int input[] = {7, 2, 3, 1, 5, 0, 5, 7, 4};
    int n = 9;

    int input2[] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    int n2 = 9;


    int *s = solve (input, n);

    for (int i = 0; i < n; i++)
    {
        printf ("%d ", s[i]);
    }
    printf ("\n");

    free (s);


    int *s2 = solve (input2, n2);

    for (int i = 0; i < n; i++)
    {
        printf ("%d ", s2[i]);
    }
    printf ("\n");

    free (s2);

    return 0;
}
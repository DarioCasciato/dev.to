// =================================
//
//  Project Title:
//
//  Description:
//
// ---------------------------------
//
// Author:
//
//  Date:
//
//  Location:
//
// =================================


typedef struct
{
    unsigned char act;
    unsigned char old;
    unsigned char edge;
    unsigned char edge_pos;
    unsigned char edge_neg;
} edge_t;

typedef struct
{
    volatile long t;
    unsigned char loopcntr;
    unsigned char pulse;
} timer_t;

enum
{
    st_idle,
    st_open,
    st_close,
    st_error
} state;


void main()
{
    edge_t btn = {0};
    timer_t time = {0};

    unsigned char input = 0;
    unsigned char output = 0;
    unsigned char P0 = 0;


    while (1)
    {
        btn.old = btn.act;
        btn.act = input;
        btn.edge = btn.act ^ btn.old;
        btn.edge_pos = btn.edge & btn.act;
        btn.edge_neg = btn.edge & btn.old;


        switch (state)
        {
            case st_idle:

                break;

            case st_open:

                break;

            case st_close:

                break;

            case st_error:

                break;


            default:
                state = st_idle;
                break;
        }

        P0 = output;


        time.pulse = 0;

        if(time.loopcntr++ >= 100)
        {
            time.pulse = 1;
            time.loopcntr = 0;
        }

        for(time.t; time.t >= 12000000; time.t++);
    }
}
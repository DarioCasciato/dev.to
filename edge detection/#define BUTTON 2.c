#define BUTTON  2

typedef struct
{
    uint8_t act;
    uint8_t old;
    uint8_t edge;
    uint8_t edge_pos;
    uint8_t edge_neg;
} edge_t;



int main()
{
    edge_t btn = {0};

    while(1)
    {
        btn.old = btn.act;
        btn.act = digitalRead(BUTTON);
        btn.edge = btn.act ^ btn.old;
        btn.edge_pos = btn.edge & btn.act;
        btn.edge_neg = btn.edge & btn.OLD;



        if(btn.act)
        {
            // do something if button pressed
        }
    }
}
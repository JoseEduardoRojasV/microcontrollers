#ifndef INPUT_H
#define INPUT_H

/*
The DDxn bit in the DDRx Register selects the direction of this pin.
If DDxn is written logic one, Pxn is configured as an output pin.
If DDxn is written logic zero, Pxn is configured as an input pin.
*/

class Input
{
private:
    /* data */
public:
    Input(/* args */);
    ~Input();
};

Input::Input(/* args */)
{
}

Input::~Input()
{
}


#endif
#ifndef SCREEN_
#define SCREEN_


class Screen
{
public:
    Screen() {}
    
    virtual ~Screen() {}

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Reset()  = 0;

private:

};

#endif
#ifndef STORYSTACK_H
#define STORYSTACK_H

class StoryStack
{
private:
    int *stackArray;
    int stackSizel
    int top;
public:
    StoryStack(int);
    StoryStack(const StoryStack &);
    ~StoryStack();
    void push(int);
    void pop(int &);
};



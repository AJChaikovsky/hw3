#ifndef EVENT_H
#define EVENT_H

struct Event {
  int time;
  int wireId;
  char state;
}

struct EventLess {
  bool operator()(const Event* a, const Event* b) const {
    return a->time < b->time;
  }
};

#endif
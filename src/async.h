#ifndef SRC_ASYNC_H_
#define SRC_ASYNC_H_

#include "napi.h"

class AsyncWorker : public Napi::AsyncWorker {
  public:
    AsyncWorker(Napi::Function& callback);
    ~AsyncWorker();

    void Execute() override;
    void OnOK() override;
    void OnError(const Napi::Error& error) override;
};

#endif  // SRC_ASYNC_H_

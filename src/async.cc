#include <unistd.h>

#include "async.h"

AsyncWorker::AsyncWorker(Napi::Function& callback)
  : Napi::AsyncWorker(callback) {}

AsyncWorker::~AsyncWorker() = default;

void AsyncWorker::Execute() {
  sleep(5);
}

void AsyncWorker::OnOK() {
  Napi::HandleScope scope(Env());
  Callback().Call({
    Env().Undefined()
  });
}

void AsyncWorker::OnError(const Napi::Error& error) {
  Napi::HandleScope scope(Env());
  Callback().Call({
    error.Value()
  });
}

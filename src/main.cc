#include "napi.h"
#include "async.h"

namespace {

Napi::Value StartAsyncWork(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function callback = info[0].As<Napi::Function>();
  auto* worker = new AsyncWorker(callback);
  worker->Queue();
  return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("startAsyncWork", Napi::Function::New(env, StartAsyncWork));
  return exports;
}

}  // namespace

NODE_API_MODULE(Test, Init)

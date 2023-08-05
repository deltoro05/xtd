#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

namespace {
  // https://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
  void SetThreadName(DWORD dwThreadID, const char* threadName) {
#pragma pack(push, 8)
    struct THREADNAME_INFO {
      DWORD dwType;
      LPCSTR szName;
      DWORD dwThreadID;
      DWORD dwFlags;
    };
#pragma pack(pop)
    
#pragma warning(push)
#pragma warning(disable: 6320 6322)
    __try {
      THREADNAME_INFO info {0x1000, threadName, dwThreadID, 0};
      RaiseException(0x406D1388, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
#pragma warning(pop)
  }
}

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return TerminateThread(reinterpret_cast<HANDLE>(handle), -1) != FALSE;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(GetCurrentThread());
}

bool thread::resume(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return ResumeThread(reinterpret_cast<HANDLE>(handle)) != -1;
}

bool thread::set_current_thread_name(const std::string& name) {
  SetThreadName(GetCurrentThreadId(), name.c_str());
  return true;
}

bool thread::set_priority(intmax_t handle, int_least32_t priority) {
  return SetThreadPriority((HANDLE)handle, priority - 2) != FALSE;
}

bool thread::suspend(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return SuspendThread(reinterpret_cast<HANDLE>(handle)) != -1;
}

#include "../../include/xtd/math.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/overflow_exception.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace xtd;

namespace {
}

decimal math::abs(decimal value) {
  return value < 0 ? -value : value;
}

double math::abs(double value) {
  return value < 0 ? -value : value;
}

float math::abs(float value) {
  return value < 0 ? -value : value;
}

int16 math::abs(int16 value) {
  if (value == numeric_limits<int16>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int32 math::abs(int32 value) {
  if (value == numeric_limits<int32>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int64 math::abs(int64 value) {
  if (value == numeric_limits<int64>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

sbyte math::abs(sbyte value) {
  if (value == numeric_limits<sbyte>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

slong math::abs(slong value) {
  if (value == numeric_limits<slong>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

double math::acos(double value) {
  return std::acos(value);
}

double math::asin(double value) {
  return std::asin(value);
}

double math::atan(double value) {
  return std::atan(value);
}

double math::atan2(double y, double x) {
  return is_infinity(y) && is_infinity(x) ? NaN : std::atan2(y, x);
}

int64 math::big_mul(int32 a, int32 b) {
  return as<int64>(a) * as<int64>(b);
}

decimal math::ceiling(decimal value) {
  return std::ceil(value);
}

double math::ceiling(double value) {
  return std::ceil(value);
}

xtd::byte math::clamp(xtd::byte value, xtd::byte min, xtd::byte max) noexcept {
  return std::clamp(value, min, max);
}

decimal math::clamp(decimal value, decimal min, decimal max) noexcept {
  return std::clamp(value, min, max);
}

double math::clamp(double value, double min, double max) noexcept {
  return std::clamp(value, min, max);
}

int16 math::clamp(int16 value, int16 min, int16 max) noexcept {
  return std::clamp(value, min, max);
}

int32 math::clamp(int32 value, int32 min, int32 max) noexcept {
  return std::clamp(value, min, max);
}

int64 math::clamp(int64 value, int64 min, int64 max) noexcept {
  return std::clamp(value, min, max);
}

slong math::clamp(slong value, slong min, slong max) noexcept {
  return std::clamp(value, min, max);
}

sbyte math::clamp(sbyte value, sbyte min, sbyte max) noexcept {
  return std::clamp(value, min, max);
}

float math::clamp(float value, float min, float max) noexcept {
  return std::clamp(value, min, max);
}

uint16 math::clamp(uint16 value, uint16 min, uint16 max) noexcept {
  return std::clamp(value, min, max);
}

uint32 math::clamp(uint32 value, uint32 min, uint32 max) noexcept {
  return std::clamp(value, min, max);
}

uint64 math::clamp(uint64 value, uint64 min, uint64 max) noexcept {
  return std::clamp(value, min, max);
}

ulong math::clamp(ulong value, ulong min, ulong max) noexcept {
  return std::clamp(value, min, max);
}

double math::cos(double value) {
  return std::cos(value);
}

double math::cosh(double value) {
  return std::cosh(value);
}

double math::degrees_to_radians(double degrees) noexcept {
  return degrees * (math::pi / 180);
}

int32 math::div_rem(int32 dividend, int32 divisor, int32& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

int64 math::div_rem(int64 dividend, int64 divisor, int64& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

double math::exp(double value) {
  return std::exp(value);
}

double math::ieee_remainder(double dividend, double divisor) {
  return divisor == 0 ? NaN : dividend - (divisor * math::round(dividend / divisor));
}

decimal math::floor(decimal value) {
  return std::floor(value);
}

double math::floor(double value) {
  return std::floor(value);
}

bool math::is_infinity(double value) noexcept {
  return is_negative_infinity(value) || is_positive_infinity(value);
}

bool math::is_negative_infinity(double value) noexcept {
  return value <= negative_infinity;
}

bool math::is_positive_infinity(double value) noexcept {
  return value >= positive_infinity;
}

bool math::is_NaN(double value) noexcept {
  return value != value;
}

double math::log(double value) {
  return std::log(value);
}

double math::log(double a, double newBase) {
  if (a < 0 || newBase < 0 || (a != 1 && newBase == 0) || (a != 1 && math::is_positive_infinity(newBase)) || math::is_NaN(a) || math::is_NaN(newBase) || newBase == 1) return math::NaN;
  if ((a == 0 && 0 < newBase && newBase < 1) || (math::is_positive_infinity(a) && newBase > 1)) return math::positive_infinity;
  if ((a == 0 && newBase > 1) || (math::is_positive_infinity(a) && 0 < newBase && newBase < 1)) return math::negative_infinity;
  return (math::log(a) / math::log(newBase));
}

double math::log10(double value) {
  return std::log10(value);
}

xtd::byte math::max(xtd::byte a, xtd::byte b) noexcept {
  return a > b ? a : b;
}

decimal math::max(decimal a, decimal b) noexcept {
  return a > b ? a : b;
}

double math::max(double a, double b) noexcept {
  return a > b ? a : b;
}

int16 math::max(int16 a, int16 b) noexcept {
  return a > b ? a : b;
}

int32 math::max(int32 a, int32 b) noexcept {
  return a > b ? a : b;
}

int64 math::max(int64 a, int64 b) noexcept {
  return a > b ? a : b;
}

slong math::max(slong a, slong b) noexcept {
  return a > b ? a : b;
}

sbyte math::max(sbyte a, sbyte b) noexcept {
  return a > b ? a : b;
}

float math::max(float a, float b) noexcept {
  return a > b ? a : b;
}

uint16 math::max(uint16 a, uint16 b) noexcept {
  return a > b ? a : b;
}

uint32 math::max(uint32 a, uint32 b) noexcept {
  return a > b ? a : b;
}

uint64 math::max(uint64 a, uint64 b) noexcept {
  return a > b ? a : b;
}

ulong math::max(ulong a, ulong b) noexcept {
  return a > b ? a : b;
}

xtd::byte math::min(xtd::byte a, xtd::byte b) noexcept {
  return a < b ? a : b;
}

decimal math::min(decimal a, decimal b) noexcept {
  return a < b ? a : b;
}

double math::min(double a, double b) noexcept {
  return a < b ? a : b;
}

int16 math::min(int16 a, int16 b) noexcept {
  return a < b ? a : b;
}

int32 math::min(int32 a, int32 b) noexcept {
  return a < b ? a : b;
}

int64 math::min(int64 a, int64 b) noexcept {
  return a < b ? a : b;
}

slong math::min(slong a, slong b) noexcept {
  return a < b ? a : b;
}

sbyte math::min(sbyte a, sbyte b) noexcept {
  return a < b ? a : b;
}

float math::min(float a, float b) noexcept {
  return a < b ? a : b;
}

uint16 math::min(uint16 a, uint16 b) noexcept {
  return a < b ? a : b;
}

uint32 math::min(uint32 a, uint32 b) noexcept {
  return a < b ? a : b;
}

uint64 math::min(uint64 a, uint64 b) noexcept {
  return a < b ? a : b;
}

ulong math::min(ulong a, ulong b) noexcept {
  return a < b ? a : b;
}

double math::pow(double x, double y) {
  return std::pow(x, y);
}

double math::radians_to_degrees(double radians) noexcept {
  return radians * (180 / math::pi);
}

decimal math::round(decimal value) {
  return math::round(value, 0);
}

decimal math::round(decimal value, int32 decimals) {
  decimal muliplicator = 1;
  for (int32 index = 0; index < decimals; index++)
    muliplicator *= 10;
  return math::floor((value * muliplicator) + 0.5) / muliplicator;
}

double math::round(double value) {
  return math::round(value, 0);
}

double math::round(double value, int32 decimals) {
  double multiplicator = 1.0;
  for (int32 index = 0; index < decimals; index++)
    multiplicator *= 10.0;
  return math::floor((value * multiplicator) + 0.5) / multiplicator;
}

int32 math::sign(decimal value) {
  if (value != value) throw arithmetic_exception(csf_);
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32 math::sign(double value) {
  if (is_NaN(value)) throw arithmetic_exception(csf_);
  return value < 0.0 ? -1 : value == 0.0 ? 0 : 1;
}

int32 math::sign(int16 value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32 math::sign(int32 value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32 math::sign(int64 value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32 math::sign(sbyte value) {
  return value < 0 ? -1 : value == 0 ? 0 : 1;
}

int32 math::sign(float value) {
  if (value != value) throw arithmetic_exception(csf_);
  return value < 0.0f ? -1 : value == 0.0f ? 0 : 1;
}

double math::sin(double value) {
  return std::sin(value);
}

double math::sinh(double value) {
  return std::sinh(value);
}

double math::sqrt(double value) {
  return std::sqrt(value);
}

double math::tan(double value) {
  return std::tan(value);
}

double math::tanh(double value) {
  return std::tanh(value);
}

decimal math::truncate(decimal value) {
  return (value > 0) ? math::floor(value) : math::ceiling(value);
}

double math::truncate(double value) {
  return (value > 0) ? math::floor(value) : math::ceiling(value);
}

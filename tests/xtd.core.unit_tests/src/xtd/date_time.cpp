#include <sstream>
#include <xtd/date_time.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_date_time) {
    static std::tm make_tm(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
      std::tm date = {};
      date.tm_year = year - 1900;
      date.tm_mon = month - 1;
      date.tm_mday = day;
      date.tm_hour = hour;
      date.tm_min = minute;
      date.tm_sec = second;
      return date;
    }

  public:
    void test_method_(create_date_with_default_constructor) {
      date_time d;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::is_zero(d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_year_month_day) {
      date_time d(1971, 1, 5);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(1971U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(5U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1971-01-05 00:00:00", d.to_string("u"), csf_);
    }

    void test_method_(create_date_max_value) {
      date_time d = date_time::max_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(ticks(3155378975999999999LL), d.ticks(), csf_);
      assert::are_equal(9999U, d.year(), csf_);
      assert::are_equal(12U, d.month(), csf_);
      assert::are_equal(31U, d.day(), csf_);
      assert::are_equal(23U, d.hour(), csf_);
      assert::are_equal(59U, d.minute(), csf_);
      assert::are_equal(59U, d.second(), csf_);
      assert::are_equal("9999-12-31 23:59:59", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_min_value) {
      date_time d = date_time::min_value;
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::is_zero(d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1-01-01 00:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks) {
      date_time d(duration_cast<ticks>(seconds(42)));
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(seconds(42)), d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::are_equal(42U, d.second(), csf_);
      assert::are_equal("1-01-01 00:00:42", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_loacal) {
      date_time d(duration_cast<ticks>(minutes(24)), date_time_kind::local);
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(minutes(24)), d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::are_equal(24U, d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1-01-01 00:24:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_utc) {
      date_time d(duration_cast<ticks>(hours(12)), date_time_kind::utc);
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(hours(12)), d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::are_equal(12U, d.hour(), csf_);
      assert::is_zero(d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1-01-01 12:00:00", d.to_string("u"), csf_);
    }
    
    void test_method_(create_date_with_ticks_and_date_time_kind_unspecified) {
      date_time d(duration_cast<ticks>(minutes(24)), date_time_kind::unspecified);
      assert::are_equal(date_time_kind::unspecified, d.kind(), csf_);
      assert::are_equal(duration_cast<ticks>(minutes(24)), d.ticks(), csf_);
      assert::are_equal(1U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(1U, d.day(), csf_);
      assert::is_zero(d.hour(), csf_);
      assert::are_equal(24U, d.minute(), csf_);
      assert::is_zero(d.second(), csf_);
      assert::are_equal("1-01-01 00:24:00", d.to_string("u"), csf_);
    }

    void test_method_(create_date_now) {
      assert::are_equal(date_time_kind::local, date_time::now().kind(), csf_);
      assert::is_not_zero(date_time::now().ticks().count(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::now().to_time_t(), csf_);
    }

    void test_method_(create_date_utc_now) {
      assert::are_equal(date_time_kind::utc, date_time::utc_now().kind(), csf_);
      assert::is_not_zero(date_time::now().ticks().count(), csf_);
      assert::are_equal(system_clock::to_time_t(system_clock::now()), date_time::now().to_time_t(), csf_);
    }

    void test_method_(from_time_t) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t(std::mktime(&tms));
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(1971U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(5U, d.day(), csf_);
      assert::are_equal(21U, d.hour(), csf_);
      assert::are_equal(10U, d.minute(), csf_);
      assert::are_equal(30U, d.second(), csf_);
      assert::are_equal(std::mktime(&tms), d.to_time_t(), csf_);
    }

    /*
    void test_method_(from_time_t_utc) {
      struct tm tms = make_tm(1971, 1, 5, 21, 10, 30);
      date_time d = date_time::from_time_t_utc(std::mktime(&tms));
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(1971U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(5U, d.day(), csf_);
      assert::are_equal(21U, d.hour(), csf_);
      assert::are_equal(10U, d.minute(), csf_);
      assert::are_equal(30U, d.second(), csf_);
      assert::are_equal(std::mktime(&tms), d.to_time_t(), csf_);
    } */

    void test_method_(from_tm) {
      date_time d = date_time::from_tm(make_tm(1971, 1, 5, 21, 10, 30));
      assert::are_equal(date_time_kind::local, d.kind(), csf_);
      assert::are_equal(1971U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(5U, d.day(), csf_);
      assert::are_equal(21U, d.hour(), csf_);
      assert::are_equal(10U, d.minute(), csf_);
      assert::are_equal(30U, d.second(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }

    void test_method_(from_tm_utc) {
      date_time d = date_time::from_tm_utc(make_tm(1971, 1, 5, 21, 10, 30));
      assert::are_equal(date_time_kind::utc, d.kind(), csf_);
      assert::are_equal(1971U, d.year(), csf_);
      assert::are_equal(1U, d.month(), csf_);
      assert::are_equal(5U, d.day(), csf_);
      assert::are_equal(21U, d.hour(), csf_);
      assert::are_equal(10U, d.minute(), csf_);
      assert::are_equal(30U, d.second(), csf_);
      assert::are_equal("1971-01-05 21:10:30", d.to_string("u"), csf_);
    }
  };
}

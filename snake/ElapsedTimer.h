#ifndef ELAPSED_TIMER_H
#define ELAPSED_TIMER_H


#include <chrono>
#include <string>
#include <cstdint>


// since std::is_clock_v become available C++20
template <typename T>
struct is_std_clock {
	static const bool value{ std::is_same<T, std::chrono::system_clock>::value || std::is_same<T, std::chrono::steady_clock>::value || std::is_same<T, std::chrono::high_resolution_clock>::value };
};

template <typename TimeT = std::chrono::high_resolution_clock>
class ElapsedTimer
{
	static_assert(is_std_clock<TimeT>::value, "Invalide template argument in Duration class : TimeT must be a std::clock from std::chrono.");
	std::chrono::time_point<TimeT> mRefTimePoint;

public:
	// Constructor.
	ElapsedTimer() : mRefTimePoint{ TimeT::now() } {}

	// Set now as referential point in time.
	void start() { mRefTimePoint = TimeT::now(); }

	// Set now as referential point in time and return the elapsed time since 
	// the last referential point.
	int64_t restart() { int64_t duration{ elapsed() }; start(); return duration; }

	// Return the elapsed time since the last referential point without 
	// reseting the referential point. 
	int64_t elapsed() const { return (TimeT::now() - mRefTimePoint).count(); }

	// Return the base of time (tic per second).
	constexpr int64_t baseTime() const { return std::chrono::high_resolution_clock::period::den; }

	// Utility fonction returning duration in seconds
	double restartSeconds() { return static_cast<double>(restart()) / baseTime(); }
	double elapsedSeconds() const { return static_cast<double>(elapsed()) / baseTime(); }
};

#endif // ELAPSED_TIMER_H
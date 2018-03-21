// -*- c++ -*-
#pragma once

#include <string>
#include <map>
#include <memory>

namespace copter
{
    class CopterStrategy
    {
        enum class Direction { NONE = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4, STAY = 5 };
        static constexpr int MEMORY_SIZE = 10;

    public:
        virtual ~CopterStrategy() {}

        // get the copter strategy name
        virtual const std::string &get_name() const noexcept = 0;

        // get the amount of memory in this quadrocopter
        virtual size_t get_memory_size() const noexcept = 0;

        // sets the total number of the copters on the field
        virtual void set_copter_count(int copter_count) = 0;
        // sets the target position for i-th copter
        virtual void set_target_pos(int i, int x, int y) = 0;
        // sets the memory state of this copter
        virtual void set_memory(const unsigned char *mem, size_t size) = 0;
        // sets the number of neighbouring copters
        virtual void set_neighbour_count(int neighbour_count) = 0;
        // sets the direction from the current to the i-th neighbouring copter
        virtual void set_neighbour_dir(int i, Direction dir) = 0;
        // sets the memory state of the i-th neighbouring copter
        virtual void set_neighbour_memory(int i, const unsigned char *mem, size_t size) = 0;

        // calculate the next move
        virtual void compute_move() = 0;

        // get the resulting direction of the copter
        virtual Direction get_dir() const noexcept = 0;
        // copy out the resulting memory state
        virtual size_t get_memory(unsigned char *mem, size_t size) const noexcept = 0;
    };

    class CopterStrategyFactory
    {
    public:
        virtual ~CopterStrategyFactory() {}

        // get the copter strategy name
        virtual const std::string &get_name() const noexcept = 0;

        // create and return new strategy object
        virtual CopterStrategy *new_strategy() = 0;
    };

    // the managing class, singleton
    class CopterStrategyFactoryManager
    {
        using container_type = std::map<std::string, std::unique_ptr<CopterStrategyFactory> >;
        container_type factories;

    public:
        static CopterStrategyFactoryManager &instance();

        // the 'strategy' pointer is managed by this class
        // it will be freed automatically
        void register_strategy(CopterStrategyFactory *strategy)
        {
            if (strategy) {
                factories.emplace(strategy->get_name(), std::unique_ptr<CopterStrategyFactory>(strategy));
            }
        }
        CopterStrategyFactory *find_strategy(const std::string &name) const noexcept
        {
            if (auto it = factories.find(name); it != factories.end()) {
                return it->second.get();
            } else {
                return nullptr;
            }
        }
        container_type::const_iterator begin() const noexcept { return factories.cbegin(); }
        container_type::const_iterator end() const noexcept { return factories.cend(); }
    };
}

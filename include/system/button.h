#ifndef BUTTON_H
#define BUTTON_H

#include "digitalIO.h"
#include <stdbool.h>

typedef struct button_s {
    pin_t pin;
    state_t state;
    state_t prev_state;
} button_t;

/**
 * @brief Constructs a new `button_t` object
 * @param port a `port_t` enum value describing the port in which the button is connected to
 * @param port_bit the number of the bit within the port in which the button is connected to
 * @param mode either `INPUT` or `INPUT_PULLUP` depending on the type of button
 * @return `button_t` object to control the button with
 */
extern const button_t button_construct(port_t port, uint8_t port_bit, pin_mode_t mode);

/**
 * @brief Updates the button's state
 * @param button Pointer to the `button_t` to update
 * @return the current state of the button
 */
extern state_t button_update_state(button_t* button);

/**
 * @brief Returns whether or not `button` is pressed down
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button is pressed down, `false` otherwise
 */
extern bool button_being_pressed(button_t* button);

/**
 * @brief Returns whether or not `button` was just released
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button has just been released, `false` otherwise
 */
extern bool button_released_event(button_t* button);

/**
 * @brief Returns whether or not `button` was just pressed
 * @param button Pointer to the `button_t` to read from
 * @return `true` if button has just been pressed, `false` otherwise
 */
extern bool button_pushed_event(button_t* button);

#endif //BUTTON_H
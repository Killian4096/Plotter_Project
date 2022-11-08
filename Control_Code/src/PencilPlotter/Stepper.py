#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time
class Stepper:
    def __init__(self, state, hardware_function):
        self.state = state
        self.run_stepper()
        self.hardware_function = hardware_function
    
    def increase_state(self):
        self.state += 1
        if self.state > 7:
            self.state = 0
        self.run_stepper()
    
    def decrease_state(self):
        self.state -= 1
        if self.state < 0:
            self.state = 7
        self.run_stepper()
    
    def get_state(self):
        return self.state
    
    def run_stepper(self):
        print("--Command--")
        print(self.get_state())
        print("-----------")
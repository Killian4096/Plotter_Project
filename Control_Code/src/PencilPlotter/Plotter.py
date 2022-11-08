#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from Stepper import Stepper

class Plotter():
    def __init__(self):
        self.steppers = []
    
    def add_stepper(self, state, hardware_function):
        self.steppers.append()
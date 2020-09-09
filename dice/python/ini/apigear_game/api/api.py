from typing import Iterable
from enum import Enum

class IDice:
    @property
    def value(self):
        raise NotImplementedError

    def toss(self):
        raise NotImplementedError

class IRandom:

    def generate(self, min: int, max: int):
        raise NotImplementedError

#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_

float mf_lerp(float from, float to, float weight) {
    return from + (weight * (to - from));
}

#endif // MATHFUNCTIONS_H_
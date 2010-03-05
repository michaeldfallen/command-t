#include "match.h"
#include "matcher.h"

VALUE mCommandT         = 0; // module CommandT
VALUE cCommandTMatch    = 0; // class CommandT::Match
VALUE cCommandTMatcher  = 0; // class CommandT::Matcher

void Init_ext()
{
    // module CommandT
    mCommandT = rb_define_module("CommandT");

    // class CommandT::Match
    cCommandTMatch = rb_define_class_under(mCommandT, "Match", rb_cObject);

    // methods
    rb_define_method(cCommandTMatch, "initialize", CommandTMatch_initialize, 2);
    rb_define_method(cCommandTMatch, "matches?", CommandTMatch_matches, 0);
    rb_define_method(cCommandTMatch, "score", CommandTMatch_score, 0);
    rb_define_method(cCommandTMatch, "to_s", CommandTMatch_to_s, 0);

    // attributes
    rb_define_attr(cCommandTMatch, "offsets", Qtrue, Qfalse); // reader = true, writer = false

    // class CommandT::Matcher
    cCommandTMatcher = rb_define_class_under(mCommandT, "Matcher", rb_cObject);

    // methods
    rb_define_method(cCommandTMatcher, "initialize", CommandTMatcher_initialize, 1);
    rb_define_method(cCommandTMatcher, "sorted_matches_for", CommandTMatcher_sorted_matchers_for, 2);
    rb_define_method(cCommandTMatcher, "matches_for", CommandTMatcher_matches_for, 1);
}
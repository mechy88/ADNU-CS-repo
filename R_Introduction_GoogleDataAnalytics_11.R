library("tidyverse")
library("ggplot2")
library("readr")

bookings <- read_csv("hotel_bookings.csv")

ggplot(data = bookings ) +
  geom_bar(aes(x = hotel, fill = market_segment)) +
  facet_wrap(~market_segment)

online_ta_city_hotels <- filter(bookings, hotel == "City Hotel" & )
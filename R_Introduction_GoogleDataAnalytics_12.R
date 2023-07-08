# Filters and Plots

library("ggplot2")
library("tidyverse")

hotel_bookings <- read.csv("hotel_bookings.csv")

#count of bookings to market segments. Would have used profit or commissions, but data not available
#another option was to use the number of nights stay, but I'll have to review how that data is collected or its implications
ggplot(data = hotel_bookings) +
  geom_bar(mapping = aes(x = hotel, fill = market_segment))

#separated the segments to get a better view
ggplot(data = hotel_bookings) +
  geom_bar(mapping = aes(x = hotel)) +
  facet_wrap(~market_segment)

online_cityhotel_bookings <- filter(hotel_bookings, hotel == "City Hotel" & market_segment == "Online TA")

ggplot(data = online_cityhotel_bookings) +
  geom_point(mapping = aes(y = children, x = lead_time))


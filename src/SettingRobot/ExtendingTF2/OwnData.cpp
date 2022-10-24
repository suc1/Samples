namespace tf2
{
/**\brief The templated function expected to be able to do a transform
 *
 * This is the method which tf2 will use to try to apply a transform for any given datatype.   
 * \param data_in The data to be transformed.
 * \param data_out A reference to the output data.  Note this can point to data in and the method should be mutation safe.
 * \param transform The transform to apply to data_in to fill data_out.  
 * 
 * This method needs to be implemented by client library developers
 */
template <class T>
  void doTransform(const T& data_in, T& data_out, const geometry_msgs::TransformStamped& transform);

/**\brief Get the timestamp from data 
 * \param t The data input.
 * \return The timestamp associated with the data. 
 */
template <class T>
  const ros::Time& getTimestamp(const T& t);

/**\brief Get the frame_id from data 
 * \param t The data input.
 * \return The frame_id associated with the data. 
 */
template <class T>
  const std::string& getFrameId(const T& t);
}